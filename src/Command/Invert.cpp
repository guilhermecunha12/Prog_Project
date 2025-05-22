//
// Created by pedro on 5/8/25.
//
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "sstream"

namespace prog {
    namespace command {
        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {}

        Image *Invert::apply(Image *img) {

            // Selecionar uma linha da imagem
            for (int y = 0; y < img->height(); y++) {
                // Percorrer a linha selecionada da imagem
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

        std::string Invert::toString() const {
            std::ostringstream out;
            out << name() << " image";
            return out.str();
        }
    }
}