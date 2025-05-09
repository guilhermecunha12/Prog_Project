//
// Created by pedro on 5/9/25.
//

#include "Command/rotate_right.hpp"
#include <sstream>
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        rotate_right::rotate_right() : Command("rotate_right") {}

        rotate_right::~rotate_right() {}

        Image *rotate_right::apply(Image *img) {
            /* Criamos a nova imagem resultante da rotação:
            A altura passa a ser a largura e a largura passa a ser a altura
            */
            Image* rotated_image = new Image(img->height(), img->width());

            // Iteramos sobre a rotated_image
            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    // A primeira linha passa a ser a última coluna e a primeira coluna passa a ser a primeira linha
                    rotated_image->at(img->height() - y - 1,x) = img->at(x, y);
                }
            }
            // Eliminamos a memória alocada da imagem anterior
            delete img;
            // img passa a ser a rotated image
            img = rotated_image;
            return img;
        }

        std::string rotate_right::toString() const {
            std::ostringstream out;
            out << name() << " Rotated the image right by 90 degrees";
            return out.str();
        }
    }
}
