//
// Created by pedro on 5/9/25.
//

#include "Command/fill.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        fill::fill(int x, int y, int w, int h, Color &color_fill)
            : Command("fill"), x_(x), y_(y), w_(w), h_(h), color_fill_(color_fill) {}

        fill::~fill() {}

        Image *fill::apply(Image *img) {
            // Iniciamos a partir do Top-left corner e terminamos quando alcançarmos o fim da imagem em altura
            for (int y = y_; y < y_ + h_ && y < img->height(); y++) {
                // Iniciamos a partir do Top-left corner e terminamos quando alcançarmos o fim da imagem em largura
                for (int x = x_; x < x_ + w_ && x < img->width(); x++) {
                    // Píxel da imagem na posição atual
                    Color& current_pixel = img->at(x, y);

                    // Alterar a cor do píxel atual tendo em conta a cor pretendida
                    current_pixel.red() = color_fill_.red();
                    current_pixel.green() = color_fill_.green();
                    current_pixel.blue() = color_fill_.blue();
                }
            }
            return img;
        }
        std::string fill::toString() const {
            std::ostringstream out;
            out << "Top left corner (x:" << x_ << " y:" << y_ << ") w:" << w_ << " h:" << h_ << " fill:" << color_fill_;
            return out.str();
        }


    }
}
