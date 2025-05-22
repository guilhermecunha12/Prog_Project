//
// Created by guilherme on 5/9/25.
//

#ifndef MOVE_HPP
#define MOVE_HPP
#include "Command.hpp"
#include "Slide.hpp"

namespace prog
{
    namespace command
    {
        // O move é um slide cujo warp é só aplicado à fill color default
        class Move final: public Slide
        {
        public:
            // Construtor
            Move(int x, int y);

            // Destrutor
            ~Move();

            // Overrides
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}
#endif //MOVE_HPP
