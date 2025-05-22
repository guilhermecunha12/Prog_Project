//
// Created by guilherme on 5/9/25.
//
#include "Command/Rotate_left.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {
        Rotate_left::Rotate_left() : Command("Rotate_left") {}

        Rotate_left::~Rotate_left() {}

        Image* Rotate_left::apply(Image* img)
        {
            // Alocar memória dinâmica para nova imagem, sendo que a nova largura é o comprimento da imagem original
            // e o novo comprimento é a largura da imagem original, uma vez que esta foi girada.
            // Os pixeis são inicializados com a fill color
            Image* res = new Image(img->height(), img->width());

            // i : índice da linha de img e da coluna de res
            for (int i = 0; i < img->height(); i++)
            {
                // j : índice da coluna de img e da linha de res
                for (int j = 0; j < img->width(); j++)
                {
                    // O último pixel de cada linha de img passa a ser o primeiro de cada coluna de res,
                    // e assim sucessivamente para os restantes pixeis
                    res->at(i, j) = img->at(img->width() - 1 - j, i);
                }
            }

            delete img; // Libertar a memória dinâmica da imagem original
            img = res;
            return img;
        }

        std::string Rotate_left::toString() const
        {
            std::ostringstream ss;
            ss << name() << " by 90 degrees";
            return ss.str();
        }
    }
}