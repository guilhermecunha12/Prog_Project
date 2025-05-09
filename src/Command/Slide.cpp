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
            //criar uma nova imagem alocada em memoria dinamica para nao haver repetição da imagem
            Image* temp = new Image(img->width(),img->height());
            // percorre as linhas da img
            for (int y = 0; y < img->height();y++) {
                // Percoree cada linha da img
                for (int x = 0; x < img->width();x++) {
                    //Verificar se ultrapassa a imagem, se for positivo ultrapassa
                    //se for negativo não ultrapssa
                    int new_x = (x+x_)%img->width();
                    int new_y = (y+y_)%img->height();

                    // Como não ultrapssa, somamos a width e height respetivamente ao x e ao y
                    if (new_x <0) {
                        new_x += img->width();
                    }
                    if (new_y < 0) {
                        new_y += img-> height();
                    }
                    //altera os pixeis
                    temp->at(new_x,new_y) = img->at(x,y);
                }
            }
            *img = *temp; // passa o temp pra img
            delete temp; // apaga o temp da memoria dinamica
            return img;
        }

        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " x: " << x_ << " y: " << y_;
            return ss.str();
        }
    }
}