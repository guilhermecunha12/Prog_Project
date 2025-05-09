//
// Created by guilherme on 5/9/25.
//
#include "Command/Move.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {
        Move::Move(int x, int y) : Command("Move"), x_(x), y_(y) {}

        Image* Move::apply(Image* img)
        {
            // Alocar memória dinâmica para nova imagem com as mesmas dimensões
            // que a imagem img com todos os pixeis com a fill color
            Image* res = new Image(img->width(), img->height());

            // Percorrer as linhas de img
            for (int y = 0; y < img->height(); y++)
            {
                // Percorrer cada linha de img
                for (int x = 0; x < img->width(); x++)
                {
                    // Apenas mover os pixeis que, ao serem deslocados, não saiam das margens da imagem.
                    // Os pixeis que sairem das margens não são copiados para o resultado
                    if (y + y_ < img->height() && x + x_ < img->width())
                    {
                        res->at(x + x_, y + y_) = img->at(x, y);
                    }
                }
            }

            delete img; // Libertar a memória dinâmica da imagem original
            img = res;
            return img;
        }

        std::string Move::toString() const
        {
            std::ostringstream ss;
            ss << name() << " Moved image by " << x_ << " x pixels and " << y_ << " y pixels";
            return ss.str();
        }
    }
}