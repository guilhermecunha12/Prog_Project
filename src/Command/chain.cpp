//
// Created by pedro on 5/11/25.
//

#include "Command/chain.hpp"
#include "ScrimParser.hpp"
#include <sstream>
#include <fstream>
#include "Logger.hpp"


namespace prog {
    namespace command {
        chain::chain(std::vector<std::string> filepaths) : Command("chain"), filepaths_(filepaths){}

        chain::~chain() {
            all_filepaths_.pop_back();
        }

        std::vector<std::string> chain::all_filepaths_;

        Image *chain::apply(Image *img) {
            // Iterar sobre o vetor de filepaths
            for (size_t i = 0; i < filepaths_.size(); i++) {
                // Criar um objeto Scrim que contém os comandos de cada argumento do chain, alocado em memória dinâmica
                Scrim* scrim = parseChain(filepaths_[i]);

                // Aplicar à imagem os comandos de cada argumento do chain
                img = scrim->run(img);

                // Após cada argumento do chain libertamos a memória dinâmica associada à cada objeto Scrim criado
                delete scrim;
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

        // Parsers específicos para chain, semelhantes aos do ScrimParser

        Scrim *chain::parseChain(const std::string &current_filename) {
            std::ifstream in(current_filename);
            return parseChain(in, current_filename);
        }


        Scrim *chain::parseChain(std::istream &input, const std::string &current_filename) {
            // Create vector where commands will be stored
            std::vector<Command *> commands;

            // Parse commands while there is input in the stream
            std::string command_name;
            while (input >> command_name) {
                if (command_name == "blank") {
                    // Ignora os parâmetros seguintes do comando
                    int trash;
                    input >> trash >> trash >> trash >> trash >> trash;
                }

                else if (command_name == "open" || command_name == "save") {
                    // Ignora os parâmetros seguintes do comando
                    std::string trash;
                    input >> trash;
                }
                else {
                    ScrimParser scrim_parser;

                    Command *command = scrim_parser.parse_command(command_name, input, current_filename);

                    if (command == nullptr) {
                        // Deallocate already allocated commands
                        for (Command *allocated_command: commands) {
                            delete allocated_command;
                        }


                        *Logger::err() << "Error while parsing command\n";
                        return nullptr;
                    }

                    commands.push_back(command);
                }
            }
            // Create a new image pipeline
            return new Scrim(commands);
        }
    }
}