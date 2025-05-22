//
// Created by Gabriel Magalhaes on 08/05/2025.
//

#include "Command/Replace.hpp"
#include "PNG.hpp"
#include "Logger.hpp"
#include <sstream>

namespace prog {
    namespace command {
        //Construtor tendo em conta os valores dados pelas cores
        Replace::Replace(Color c1, Color c2) : Command("Replace"), color1_(c1), color2_(c2){}

        //Destrutor default
        Replace::~Replace() {}

        //member functions
        //apply, aplica o comando replace à imagem
        Image *Replace::apply(Image *img) {
            // Selecionar uma linha da imagem
            for (int y = 0; y < img -> height(); y++) {
                // Percorrer a linha selecionada da imagem
                for (int x = 0; x < img -> width();x++) {
                    // passado por referência, caso seja necessário alterar
                    Color& current_color = img->at(x,y);
                    //verificar se a current-color é igual à color1_, se for, devemos alterar para color2_
                    if (current_color == color1_) {
                        //Current_color é igual a color1_, então alteramos
                        current_color = color2_;
                    }
                }
            }
            return img;
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " Color1:" << color1_ << " Color2:" << color2_;
            return ss.str();
        }
    }
}