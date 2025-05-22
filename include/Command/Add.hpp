//
// Created by pedro on 5/9/25.
//

#ifndef ADD_HPP
#define ADD_HPP
#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Add final : public Command {
        public:
            Add(std::string filename, Color& neutral_color, int x, int y);

            ~Add();

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            std::string filename_;
            Color neutral_color_;
            int x_, y_;
        };
    }
}

#endif //ADD_HPP
