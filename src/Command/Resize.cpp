//
// Created by guilherme on 5/9/25.
//
#include "Command/Resize.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {
        Resize::Resize(int x, int y, int w, int h) : Command("Resize"), x_(x), y_(y), w_(w), h_(h) {}

        Resize::~Resize() {}

        Image* Resize::apply(Image* img)
        {
            // Alocar memória dinâmica para nova imagem com as novas dimensões com todos os pixeis com a fill color
            Image* res = new Image(w_, h_);

            // Preencher a parte do resize que está compreendida dentro da imagem original,
            // aplicando o offset (x_, y_) à imagem original, que é o ponto de partida para o resize
            // Selecionar uma linha da imagem
            for (int y = 0; y + y_ < img->height(); y++)
            {
                // Percorrer a linha selecionada da imagem
                for (int x = 0 ; x + x_ < img->width(); x++)
                {
                    res->at(x, y) = img->at(x + x_, y + y_);
                }
            }

            delete img; // Libertar a memória dinâmica da imagem original
            img = res;
            return img;
        }

        std::string Resize::toString() const
        {
            std::ostringstream ss;
            ss << name() << " Resized the image from pixel (" << x_ << ',' << y_ << ") with width " << w_ << " and height " << h_;
            return ss.str();
        }
    }
}