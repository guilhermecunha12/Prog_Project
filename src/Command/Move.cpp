//
// Created by guilherme on 5/9/25.
//
#include "Command/Move.hpp"
#include <sstream>
#include "Command/Crop.hpp"
#include "Command/Slide.hpp"

namespace prog
{
    namespace command
    {
        Move::Move(int x, int y) : Slide(x, y, "Move") {}

        Move::~Move() {}

        // Partir a imagem que ficaria dentro dos limites e passar ao slide
        Image* Move::apply(Image* img)
        {
            // Criar uma nova imagem que no canto superior irá conter a porção da imagem
            // que não ultrapassa os limites depois do move
            Image* new_img = new Image(img->width(), img->height());

            // Seleciona uma linha da imagem
            for (int y = 0; y < img->height() - y_; y++) {
                // Itera sobre cada linha
                for (int x = 0; x < img->width() - x_; x++) {
                    new_img->at(x, y) = img->at(x, y);
                }
            }
            // Eliminar a memória alocada da imagem anterior
            delete img;
            // img passa a ser a nova imagem
            img = new_img;
            // Aplicar o slide à imagem: este será equivalente ao move na medida em que faz warp à fill color default
            return Slide::apply(img);
        }

        std::string Move::toString() const
        {
            std::ostringstream ss;
            ss << name() << " image by x:" << x_ << " y:" << y_;
            return ss.str();
        }
    }
}
