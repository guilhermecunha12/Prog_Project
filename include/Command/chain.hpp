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

            // Destrutores
            ~chain();

            // Overrides
            Image *apply(Image *img) override;

            std::string toString() const override;

            // Parsers específicos para chain, semelhantes aos do ScrimParser
            Scrim *parseChain(std::istream &input, const std::string &filename);

            Scrim *parseChain(const std::string &filename);
        private:
            std::vector<std::string> filepaths_;
        };
    }
}


#endif //CHAIN_HPP
