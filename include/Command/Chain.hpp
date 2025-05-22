//
// Created by pedro on 5/11/25.
//

#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include "Command/Chain.hpp"
#include "ScrimParser.hpp"

namespace prog {
    namespace command {
        class Chain final : public Command {
        public:
            // Construtor
            Chain(std::vector<std::string> filepaths);

            // Destrutor
            ~Chain();

            // Função para verificar se um scrim file já está na chain global de modo a evitar recursão
            static bool in_global_chain(const std::string& filepath);

            // Static field do vetor que guarda globalmente, para todos os objetos chain,
            // todos os filepaths que contêm o comando chain
            static std::vector<std::string> all_filepaths_;

            // Overrides
            Image *apply(Image *img) override;

            std::string toString() const override;

            // Parsers específicos para chain, semelhantes aos do ScrimParser, para ignorar os comandos save, blank e open
            // Static, porque são globais à classe
            //static Scrim *parseChain(std::istream &input, const std::string &current_filename);

            //static Scrim *parseChain(const std::string &current_filename);

        private:
            // Filepaths dos scrims do chain
            std::vector<std::string> filepaths_;
        };
    }
}


#endif //CHAIN_HPP
