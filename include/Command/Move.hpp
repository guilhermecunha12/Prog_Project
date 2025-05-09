//
// Created by guilherme on 5/9/25.
//

#ifndef MOVE_HPP
#define MOVE_HPP
#include "Command.hpp"

namespace prog
{
    namespace command
    {
        class Move : public Command
        {
        public:
            // Construtor
            Move(int x, int y);

            // Overrides
            Image* apply(Image* img) override;
            std::string toString() const override;

        private:
            int x_, y_;
        };
    }
}
#endif //MOVE_HPP
