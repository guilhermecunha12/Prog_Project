//
// Created by pedro on 5/9/25.
//

#ifndef ROTATE_RIGHT_HPP
#define ROTATE_RIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Rotate_right final : public Command {
        public:
            Rotate_right();

            ~Rotate_right();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //ROTATE_RIGHT_HPP
