//
// Created by Gabriel Magalhaes on 09/05/2025.
//

#include "Command/Slide.hpp"
#include "sstream"

namespace prog {
    namespace command {
        // Construtor
        Slide::Slide(int x, int y) : Command("Slide"),x_(x),y_(y) {}
        // Destrutor default
        Slide::~Slide() {}
        // member functions
        Image *Slide::apply(Image *img) {
            //Criar uma nova imagem alocada em memória dinâmica para não haver repetição da imagem
            Image* temp = new Image(img->width(),img->height());
            // percorre as linhas da img
            for (int y = 0; y < img->height();y++) {
                // Percorre cada linha da img
                for (int x = 0; x < img->width();x++) {

                    int new_x = (x + x_) % img->width();
                    int new_y = (y + y_) % img->height();
                    //altera os pixeis
                    temp->at(new_x,new_y) = img->at(x,y);
                }
            }
            delete img; // Liberta a memória dinâmica associada a img
            img = temp; // passa o temp pra img
            return img;
        }

        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " x: " << x_ << " y: " << y_;
            return ss.str();
        }
    }
}