//
// Created by pedro on 5/9/25.
//

#include "Command/Crop.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Crop::Crop(int x, int y, int w, int h) : Resize(x, y, w, h, "Crop") {}

        Crop::~Crop() {}

        Image *Crop::apply(Image *img) {
            // Podemos alterar os member fields diretamente uma vez que estes estão protected
            // Garante que os limites da imagem original nunca são ultrapassados
            w_ = w_ < img->width() - x_ ? w_ : img->width() - x_;
            h_ = h_ < img->height() - y_ ? h_ : img->height() - y_;
            // O crop é um resize até aos limites da imagem
            return Resize::apply(img);
        }

        std::string Crop::toString() const {
            std::ostringstream out;
            out << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return out.str();
        }
    }
}