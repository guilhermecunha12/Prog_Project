//
// Created by pedro on 5/11/25.
//

#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include "Command/chain.hpp"
#include "ScrimParser.hpp"

namespace prog {
    namespace command {
        class chain : public Command {
        public:
            // Construtor
            chain(std::vector<std::string> filepaths);

            // Destrutor
            ~chain();

            // Static field do vetor que guarda todos os filepaths processados
            static std::vector<std::string> all_filepaths_;

            // Overrides
            Image *apply(Image *img) override;

            std::string toString() const override;

            // Parsers específicos para chain, semelhantes aos do ScrimParser, para ignorar os comandos save, blank e open
            Scrim *parseChain(std::istream &input, const std::string &current_filename);

            Scrim *parseChain(const std::string &current_filename);
        private:
            std::vector<std::string> filepaths_;

        };
    }
}


#endif //CHAIN_HPP
