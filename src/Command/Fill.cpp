//
// Created by pedro on 5/9/25.
//

#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Fill::Fill(int x, int y, int w, int h, Color &color_fill)
            : Command("Fill"), x_(x), y_(y), w_(w), h_(h), color_fill_(color_fill) {}

        Fill::~Fill() {}

        Image *Fill::apply(Image *img) {
            // Iniciamos a partir do Top-left corner e terminamos quando alcançarmos o fim da imagem em altura
            for (int y = y_; y < y_ + h_ && y < img->height(); y++) {
                // Iniciamos a partir do Top-left corner e terminamos quando alcançarmos o fim da imagem em largura
                for (int x = x_; x < x_ + w_ && x < img->width(); x++) {
                    // Alterar a cor do píxel atual tendo em conta a cor pretendida
                    img->at(x, y) = color_fill_;
                }
            }
            return img;
        }
        std::string Fill::toString() const {
            std::ostringstream out;
            out << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_ << " fill:" << color_fill_;
            return out.str();
        }
    }
}
