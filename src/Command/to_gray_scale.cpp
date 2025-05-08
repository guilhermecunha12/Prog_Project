//
// Created by guilherme on 5/8/25.
//
#include "Command/to_gray_scale.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {
        To_gray_scale::To_gray_scale() : Command("To_gray_scale") {}

        Image* To_gray_scale::apply(Image* img)
        {
            for (int y = 0; y < img->height(); y++)
            {
                for (int x = 0; x < img->width(); x++)
                {
                    // Pixel a alterar, por isso é criada uma referência
                    Color& pixel = img->at(x, y);
                    rgb_value v = (pixel.red() + pixel.green() + pixel.blue()) / 3;

                    pixel.red() = v;
                    pixel.green() = v;
                    pixel.blue() = v;
                }
            }

            return img;
        }

        std::string To_gray_scale::toString() const
        {
            std::ostringstream ss;
            ss << name() << " Image in gray scale";
            return ss.str();
        }

    }
}
