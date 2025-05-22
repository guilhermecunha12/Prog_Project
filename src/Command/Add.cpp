//
// Created by pedro on 5/9/25.
//
#include "Command/Add.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include <sstream>

#include "Command/Open.hpp"

namespace prog {
    namespace command {
        Add::Add(std::string filename, Color &neutral_color, int x, int y)
            : Command("Add"), filename_(filename), neutral_color_(neutral_color), x_(x), y_(y) {
        }

        Add::~Add() {
        }

        Image *Add::apply(Image *img) {
            // Instanciar objeto capaz de abrir a imagem a adicionar
            Open open_image = Open(filename_);

            /* Abertura da imagem a adicionar
             * Tendo em conta que a imagem inicial não importa, usamos um nullptr para inicializar a mesma
            O próprio Open dá delete à imagem anterior */
            Image *image_to_add = open_image.apply(nullptr);


            // Selecionar uma linha da imagem
            for (int y = 0; y < image_to_add->height(); y++) {
                // Percorrer a linha selecionada da imagem
                for (int x = 0; x < image_to_add->width(); x++) {
                    /* Cor do píxel da imagem atual (tendo em conta que queremos adicionar
                     * a nova imagem tendo em conta o Top-corner
                     */
                    Color &current_image_color = img->at(x + x_, y + y_);

                    // Cor do píxel atual da imagem a adicionar
                    Color &image_to_add_color = image_to_add->at(x, y);

                    // Se a cor da imagem a adicionar é diferente da cor neutra copiar o pixel da imagem a adicionar
                    if (image_to_add_color != neutral_color_) {
                        current_image_color = image_to_add_color;
                    }
                }
            }
            delete image_to_add;
            return img;
        }

        std::string Add::toString() const {
            std::ostringstream out;
            out << name() << " filename:" << filename_ << " neutral_color:" << neutral_color_ << " x:" << x_ << " y:" <<
                    y_;
            return out.str();
        }
    }
}
