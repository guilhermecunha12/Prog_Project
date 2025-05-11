//
// Created by guilherme on 5/9/25.
//

#ifndef RESIZE_HPP
#define RESIZE_HPP
#include "Command.hpp"

namespace prog
{
    namespace command
    {
        class Resize : public Command
        {
        public:
            // Constructor
            Resize(int x, int y, int w, int h);

            // Destrutor
            ~Resize();

            // Overrides
            Image* apply(Image* img) override;
            std::string toString() const override;

        private:
            int x_, y_, w_, h_;
        };
    }
}
#endif //RESIZE_HPP
