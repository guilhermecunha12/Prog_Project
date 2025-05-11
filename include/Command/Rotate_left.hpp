//
// Created by guilherme on 5/9/25.
//

#ifndef ROTATE_LEFT_HPP
#define ROTATE_LEFT_HPP
#include "Command.hpp"

namespace prog
{
    namespace command
    {
        class Rotate_left : public Command
        {
        public:
            //Construtor
            Rotate_left();

            //Destrutor
            ~Rotate_left();

            //Overrides
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}
#endif //ROTATE_LEFT_HPP
