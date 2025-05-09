//
// Created by pedro on 5/9/25.
//

#ifndef fill_HPP
#define fill_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class fill : public Command {
        public:
            fill(int x, int y, int w, int h, Color& color_fill);

            ~fill();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x_, y_, w_, h_;
            Color color_fill_;

        };
    }
}

#endif //fill_HPP
