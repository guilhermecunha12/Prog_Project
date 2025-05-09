//
// Created by pedro on 5/9/25.
//

#ifndef ROTATE_RIGHT_HPP
#define ROTATE_RIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class rotate_right : public Command {
        public:
            rotate_right();

            ~rotate_right();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //ROTATE_RIGHT_HPP
