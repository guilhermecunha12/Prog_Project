//
// Created by guilherme on 5/9/25.
//
#include "Command/Resize.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {
        Resize::Resize(int x, int y, int w, int h, std::string command_name) : Command(command_name), x_(x), y_(y), w_(w), h_(h) {}

        Resize::~Resize() {}

        Image* Resize::apply(Image* img)
        {
            // Alocar memória dinâmica para nova imagem com as novas dimensões com todos os pixeis com a fill color
            Image* res = new Image(w_, h_);

            // Tendo em conta as dimensões da imagem criada, estabelecer os limites válidos dentro dos quais a imagem original se enquadra nestas dimensões
            int valid_height = h_ < img->height() - y_ ? h_ : img->height() - y_;
            int valid_width = w_ < img->width() - x_ ? w_ : img->width() - x_;

            // Selecionar uma linha da imagem
            // y: pixel da nova imagem
            // y + y_: píxel da imagem original
            for (int y = 0; y < valid_height ; y++)
            {
                // Percorrer a linha selecionada da imagem
                for (int x = 0 ; x < valid_width; x++)
                {
                    // Preencher a parte do resize que está compreendida dentro da imagem original,
                    // aplicando o offset (x_, y_) à imagem original, o ponto de partida para o resize
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