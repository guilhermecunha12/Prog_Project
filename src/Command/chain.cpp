//
// Created by pedro on 5/11/25.
//

#include "Command/chain.hpp"
#include "ScrimParser.hpp"
#include <sstream>
#include <fstream>
#include "Logger.hpp"
#include "stb/stb_image.h"


namespace prog {
    namespace command {
        chain::chain(std::vector<std::string> filepaths) : Command("Chain"), filepaths_(filepaths){}

        chain::~chain() {
            // Quando um comando chain é apagado pelo destrutor do Scrim, o filepath do ficheiro acabado de processar
            // deve ser descartado do vetor de filepaths global, uma vez que a sua chain saiu da "chain global".
            // Isto só acontece se a chain global não estiver vazia
            if (!all_filepaths_.empty()) {
                all_filepaths_.pop_back();
            }
        }

        // Static field do vetor que guarda globalmente, para todos os objetos chain,
        // todos os filepaths que contêm o comando chain
        std::vector<std::string> chain::all_filepaths_;

        // Função para verificar se um scrim file já está na chain global de modo a evitar recursão
        bool chain::in_global_chain(const std::string &filepath) {
            bool found = false;
            for (const std::string& seen_filepath : all_filepaths_) {
                if (filepath == seen_filepath) {
                    found = true;
                    break;
                }
            }
            return found;
        }

        Image *chain::apply(Image *img) {
            // Iterar sobre o vetor de filepaths (argumentos do chain)
            for (const std::string& filepath : filepaths_) {

                // Só se faz parse a scrim files que não estejam na chain global, caso contrário são ignorados
                if (!in_global_chain(filepath)) {

                    // Criar um objeto ScrimParser capaz de efetuar o parsing do ficheiro Scrim
                    ScrimParser chain_parser;

                    // Criar um objeto Scrim* que contém os comandos de cada argumento do chain, alocados em memória dinâmica
                    Scrim* chain_scrim = chain_parser.parseScrim(filepath);

                    // Foi utilizada um loop semelhante ao do Scrim::run para filtrar operações inválidas
                    // para o comando chain
                    for (Command* c: chain_scrim->getCommands()) {
                        // Verificar se o filepath atual, argumento do chain, contém ele próprio um comando chain.
                        // Se for o caso adicionar o filepath à chain global.
                        // Esta condição verifica-se antes de utilizar a função apply para cada comando, evitando recursão
                        if (c->name() == "Chain") {
                            all_filepaths_.push_back(filepath);
                        }

                        // Ignorar apenas os comandos Blank Open e Save
                        if (c->name() != "Blank" && c->name() != "Open" && c->name() != "Save") {
                            *Logger::out() << "Applying command '" << c->toString() << "'\n";
                            img = c->apply(img);
                        }
                    }
                    // Após cada argumento do chain libertamos a memória dinâmica associada a cada objeto Scrim criado
                    delete chain_scrim;
                }
            }
            return img;
        }

        std::string chain::toString() const {
            std::ostringstream out;
            out << name() << " with file(s): " << filepaths_[0];
            for (size_t i = 1; i < filepaths_.size(); i++) {
                out << ", " << filepaths_[i];
            }
            return out.str();
        }
    }
}
