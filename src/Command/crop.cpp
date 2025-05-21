//
// Created by pedro on 5/9/25.
//

#include "Command/crop.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {
        crop::crop(int x, int y, int w, int h) : Resize(x, y, w, h, "crop") {

        }

        crop::~crop() {}

        Image *crop::apply(Image *img) {
            // Garante que os limites da imagem original nunca são ultrapassados
            // Podemos alterar os member fields diretamente uma vez que estes estão protected
            w_ = w_ < img->width() - x_ ? w_ : img->width() - x_;
            h_ = h_ < img->height() - y_ ? h_ : img->height() - y_;
            return Resize::apply(img);
        }

        std::string crop::toString() const {
            std::ostringstream out;
            out << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return out.str();
        }
    }
}