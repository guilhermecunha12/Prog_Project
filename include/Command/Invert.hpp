//
// Created by pedro on 5/8/25.
//

#ifndef INVERT_HPP
#define INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert();

            ~Invert();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //INVERT_HPP
