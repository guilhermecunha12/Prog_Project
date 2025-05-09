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
            // Criamos uma nova imagem com as dimensões atualizadas
            Image* new_image = new Image(w_, h_);

            // Iteramos sobre a imagem antiga, sem ultrapassar os limites da mesma
            for (int y = y_; y < y_ + h_ && y < img->height(); y++) {
                for (int x = x_; x < x_ + w_ && x < img->width(); x++) {
                    // Cor do píxel da imagem antes do crop
                    Color& old_img_color = img->at(x, y);

                    // Atualizar Cor do pixel da imagem depois do crop
                    Color& new_img_color = new_image->at(x - x_, y - y_);

                    /*new_img_color.red() = old_img_color.red();
                    new_img_color.green() = old_img_color.green();
                    new_img_color.blue() = old_img_color.blue();*/

                    new_img_color = old_img_color;

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