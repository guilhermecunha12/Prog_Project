//
// Created by pedro on 5/9/25.
//
#include "Command/add.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include <sstream>

#include "Command/Open.hpp"

namespace prog {
    namespace command {
        add::add(std::string filename, Color &neutral_color, int x, int y)
            : Command ("add"),filename_(filename), neutral_color_(neutral_color), x_(x), y_(y){}

        add::~add() {}

        Image *add::apply(Image *img) {

            // Instanciar objeto capaz de abrir a imagem a adicionar
            Open open_image = Open(filename_);

            /* Abertura da imagem a adicionar
             * Tendo em conta que a imagem inicial não importa, usamos um nullptr para inicializar a mesma
            O próprio Open dá delete à imagem anterior */
            Image* image_to_add = open_image.apply(nullptr);


            // Iterar sobre a imagem que queremos adicionar
            for (int y = 0; y < image_to_add->height(); y++) {
                for (int x = 0; x < image_to_add->width(); x++) {
                    /* Cor do píxel da imagem atual (tendo em conta que queremos adicionar
                     * a nova imagem tendo em conta o Top-corner
                     */
                    Color& current_image_color = img->at(x + x_, y + y_);

                    // Cor do píxel atual da imagem a adicionar
                    Color& image_to_add_color = image_to_add->at(x, y);

                    // Se a cor da imagem a adicionar é diferente da cor neutra copiar o pixel da imagem a adicionar
                    if (image_to_add_color.red() != neutral_color_.red()
                        || image_to_add_color.blue() != neutral_color_.blue()
                        || image_to_add_color.green() != neutral_color_.green()) {

                        current_image_color = image_to_add_color;
                    }
                }
            }
            delete image_to_add;
            return img;
        }

        std::string add::toString() const {
            std::ostringstream out;
            out << name() << " filename:" << filename_ << " neutral_color:" << neutral_color_ << " x:" << x_ << " y:" << y_;
            return out.str();
        }
    }
}
