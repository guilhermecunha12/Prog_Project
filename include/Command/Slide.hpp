//
// Created by Gabriel Magalhaes on 09/05/2025.
//

#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Command.hpp"
#include <string>

namespace prog
{
    namespace command
    {
        class Slide : public Command
        {
        public:
            // Construtor
            Slide(int x, int y);
            //Destrutor
            ~Slide();
            //member functions
            Image* apply(Image* img) override;
            std::string toString() const override;
        private:
            int x_,y_;
        };
    }
}



#endif //SLIDE_HPP
