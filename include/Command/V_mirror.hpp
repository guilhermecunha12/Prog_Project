//
// Created by Gabriel Magalhaes on 09/05/2025.
//

#ifndef V_MIRROR_HPP
#define V_MIRROR_HPP

#include "Command.hpp"
#include <string>

namespace prog
{
    namespace command
    {
        class V_mirror : public Command
        {
        public:
            // Construtor
            V_mirror();
            //Destrutor
            ~V_mirror();
            //member functions
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}


#endif //V_MIRROR_HPP
