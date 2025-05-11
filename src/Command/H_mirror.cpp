//
// Created by guilherme on 5/8/25.
//
#include "Command/H_mirror.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {
        H_mirror::H_mirror() : Command("H_mirror") {}

        H_mirror::~H_mirror() {}

        Image* H_mirror::apply(Image* img)
        {
            // Inverter os píxeis linha a linha
            for (int y = 0; y < img->height(); y++)
            {
                // Apenas percorrer até ao linha média horizontal da imagem que será o espelho de reflexão
                for (int x = 0; x < img->width() / 2; x++)
                {
                    // Guardar variável temporária para depois usar na 2ª troca
                    const Color temp = img->at(x, y);
                    // 1ª troca, da direita para a esquerda
                    img->at(x, y) = img->at(img->width() - 1 - x, y);
                    // 2ª troca, da esquerda para a direita
                    img->at(img->width() - 1 - x, y) = temp;
                }
            }

            return img;
        }

        std::string H_mirror::toString() const
        {
            std::ostringstream ss;
            ss << name() << " Image was h-mirrored";
            return ss.str();
        }


    }
}