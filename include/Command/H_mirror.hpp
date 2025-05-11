//
// Created by guilherme on 5/8/25.
//

#ifndef H_MIRROR_H
#define H_MIRROR_H
#include "Command.hpp"

namespace prog
{
    namespace command
    {
        class H_mirror : public Command
        {
        public:
            // Construtor
            H_mirror();

            // Destrutor
            ~H_mirror();

            // Overrides
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}
#endif //H_MIRROR_H
