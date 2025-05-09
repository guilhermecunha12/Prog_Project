//
// Created by pedro on 5/8/25.
//
#include "Command/invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "sstream"

namespace prog {
    namespace command {
        invert::invert() : Command("invert") {}

        invert::~invert() {}

        Image *invert::apply(Image *img) {

            // Iterar sobre cada linha da imagem (y)
            for (int y = 0; y < img->height(); y++) {
                // Iterar sobre cada coluna da imagem (x)
                for (int x = 0; x < img->width(); x++) {
                    // Cor do pixel atual

                    Color& current_color = img->at(x, y);

                    //Utilizar os getters com referências mutáveis para inverter o valor da cor do pixel
                    current_color.red() = 255 -  current_color.red();
                    current_color.green() = 255 - current_color.green();
                    current_color.blue() = 255 - current_color.blue();
                }
            }
            return img;
        }

        std::string invert::toString() const {
            std::ostringstream out;
            out << name() << "inverted Image";
            return out.str();
        }
    }
}