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

                    //Usar o overload do operator- para atualizar o valor de current_color
                    current_color = 255 - current_color;
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