//
// Created by Gabriel Magalhaes on 08/05/2025.
//

#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            //Construtor
            Replace(Color c1,Color c2);
            //Destrutor
            ~Replace();
            //Funções definidas dentro da class
            //aplica o commando à imagem
            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            Color color1_,color2_;
        };
    }
}

#endif //PROJECT_REPLACE_HPP
