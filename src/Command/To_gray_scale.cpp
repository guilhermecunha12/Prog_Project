//
// Created by guilherme on 5/8/25.
//
#include "Command/To_gray_scale.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {
        To_gray_scale::To_gray_scale() : Command("To_gray_scale") {}

        To_gray_scale::~To_gray_scale() {}

        Image* To_gray_scale::apply(Image* img)
        {
            // Selecionar uma linha da imagem
            for (int y = 0; y < img->height(); y++)
            {
                // Percorrer a linha selecionada da imagem
                for (int x = 0; x < img->width(); x++)
                {
                    // Píxel a alterar, por isso é criada uma referência
                    Color& pixel = img->at(x, y);
                    rgb_value v = (pixel.red() + pixel.green() + pixel.blue()) / 3;

                    pixel = Color(v, v, v);
                }
            }

            return img;
        }

        std::string To_gray_scale::toString() const
        {
            std::ostringstream ss;
            ss << name() << ": image in gray scale";
            return ss.str();
        }

    }
}
