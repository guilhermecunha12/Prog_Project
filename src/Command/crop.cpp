//
// Created by pedro on 5/9/25.
//

#include "Command/crop.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {
        crop::crop(int x, int y, int w, int h) : Command("crop"), x_(x), y_(y), w_(w), h_(h) {}

        crop::~crop() {}

        Image *crop::apply(Image *img) {
            // Garante que os limites da imagem original nunca são ultrapassados
            int valid_width = w_ < img->width() - x_ ? w_ : img->width() - x_;
            int valid_height = h_ < img->height() - y_ ? h_ : img->height() - y_;

            // Criamos uma nova imagem com as dimensões atualizadas
            Image* new_image = new Image(valid_width, valid_height);

            // Iteramos sobre a imagem antiga, tendo em conta as dimensões atualizadas
            for (int y = 0; y < valid_height; y++) {
                for (int x = 0; x < valid_width; x++) {
                    // Aplica-se o offset (x_, y_) à imagem original, que é o ponto de partida para o crop
                    new_image->at(x, y) = img->at(x + x_, y + y_);
                }
            }
            // Eliminar a imagem anterior
            delete img;
            // img passa a ser a versão cropped de img, que é new_image
            img = new_image;
            return img;
        }

        std::string crop::toString() const {
            std::ostringstream out;
            out << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return out.str();
        }
    }
}