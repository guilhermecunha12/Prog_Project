//
// Created by Gabriel Magalhaes on 09/05/2025.
//

#include "Command/Scaleup.hpp"
#include <sstream>

namespace prog {
    namespace command {
        //construtor
        Scaleup::Scaleup(int x, int y) : Command("Scaleup"),x_(x),y_(y) {}

        //destrutor default
        Scaleup::~Scaleup() {}

        //member functions
        Image *Scaleup::apply(Image *img) {
            /* Alocar em memória dinâmica uma imagem temporária com a nova largura e altura conforme
             * O Scaleup, multiplicando os pixeis da largura pelo x
             * E multiplicando os pixeis da altura pelo y
            */
            Image* temp = new Image(img->width() * x_,img->height() * y_);
            //percorre as colunas da img
            for (int y = 0; y < img-> height(); y++) {
                //percorre as linhas da img
                for (int x = 0; x < img->width();x++) {
                    // o pixel atual de img
                    const Color current = img->at(x,y);
                    // 2 loops para iterar de 0 até x_ e y_, para dar multiplicar o número de pixeis
                    for (int j = 0; j < y_ ;j++) {
                        for (int i = 0; i< x_;i++) {
                            // pegamos no (x,y) do atual e multiplicamos pelo (x_,y_)
                            // uma vez que x_ y_ indica o deslocamento pelo eixo x e y respetivamente
                            // depois somamos o i e j para modificar a temp com o pixel atual
                            temp->at(x*x_ + i, y*y_ + j) = current;
                        }
                    }
                }
            }
            *img = *temp; // copiamos o temp para o img
            delete temp; // apagamos o temp da memória dinâmica
            return img;
        }

        std::string Scaleup::toString() const {
            std::ostringstream ss;
            ss << name() << " x: " << x_ << " y: " << y_;
            return ss.str();
        }
    }
}