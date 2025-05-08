//
// Created by Gabriel Magalhaes on 08/05/2025.
//

#include "Command/Replace.hpp"
#include "PNG.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <sstream>

namespace prog {
    namespace command {
        //Construtor tendo em conta os valores dados pelas cores
        Replace::Replace(Color c1, Color c2) : Command("replace"),color1_(c1),color2_(c2){}
        //Destrutor default
        Replace::~Replace() {}
        //member functions
        //apply, aplica o comando replace à imagem
        Image *Replace::apply(Image *img) {
            for (int i = 0; img -> height();i++) {
                for (int j = 0; img -> width();j++) {
                    // passado por referencia, caso seja necessario alterar
                    Color& current_color = img->at(j,i);
                    //verificar se a current-color é igual à color1_, se for, devemos alterar para color2_
                    if (current_color.red() == color1_.red() && current_color.green() == color1_.green() && current_color.blue() == color1_.blue()) {
                        //Current_color é igual a color1_,entao alteramos
                        current_color = color2_;
                    }
                }
            }
            return img;
        }
        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " Color 1:" << color1_ << " Color 2:" << color2_;
            return ss.str();
        }
    }
}