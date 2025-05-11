//
// Created by guilherme on 5/8/25.
//

#ifndef TO_GRAY_SCALE_H
#define TO_GRAY_SCALE_H
#include "Command.hpp"

namespace prog
{
    namespace command
    {
        class To_gray_scale : public Command
        {
        public:
            // Construtor
            To_gray_scale();

            // Destrutor
            ~To_gray_scale() override;

            // Override
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}
#endif //TO_GRAY_SCALE_H
