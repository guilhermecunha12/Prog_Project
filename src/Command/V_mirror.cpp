//
// Created by Gabriel Magalhaes on 09/05/2025.
//
#include "Command/V_mirror.hpp"
#include <sstream>

namespace prog {
    namespace command {
        //construtor
        V_mirror::V_mirror() : Command("V_mirror") {}

        //destrutor default
        V_mirror::~V_mirror() {}

        //member functions
        Image *V_mirror::apply(Image *img) {
            // Selecionar uma linha da imagem
            for (int y = 0; y < img-> height()/2; y++) {
                // Percorrer a linha selecionada da imagem
                for (int x = 0; x < img->width();x++) {

                    // Guardar variável temporária para depois usar na 2ª troca
                    const Color temp = img->at(x, y);
                    // 1ª troca, de baixo para cima
                    img->at(x, y) = img->at(x, img->height() -1 -y);
                    // 2ª troca, de cima para baixo
                    img->at(x, img->height() -1 -y) = temp;
                }
            }
            return img;
        }

        std::string V_mirror::toString() const {
            std::ostringstream ss;
            ss << name() << " Image was V-mirrored";
            return ss.str();
        }

    }
}