//
// Created by Gabriel Magalhaes on 09/05/2025.
//

#ifndef SCALEUP_HPP
#define SCALEUP_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Scaleup : public Command {
        public:
            //Construtor
            Scaleup(int x,int y);
            //Destrutor
            ~Scaleup();
            //member funcionts
            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            int x_,y_;
        };
    }
}

#endif //SCALEUP_HPP
