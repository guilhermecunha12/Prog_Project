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
            // Adicionou-se o quinto argumento para que o crop possa ser subclasse de resize e passar o seu nome à classe Command
            Resize(int x, int y, int w, int h, std::string command_name = "Resize");

            // Destrutor
            ~Resize();

            // Overrides
            Image* apply(Image* img) override;
            std::string toString() const override;

        // Permitem que os member fields sejam acessíveis pela subclasse crop
        protected:
            int x_, y_, w_, h_;
        };
    }
}
#endif //RESIZE_HPP
