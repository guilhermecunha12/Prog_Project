#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) : width_(w), height_(h) {

        for (int i = 0; i < h ; i++) // A imagem tem h linhas
        {
            std::vector<Color> line;

            for (int j = 0; j < w; j++)
            {
                line.push_back(fill); // Popular cada linha
            }
            pixels.push_back(line); // Adicionar nova linha à matriz
        }
    }

    Image::~Image() {
    }

    // Getter da largura da imagem
    int Image::width() const {
        return width_;
    }

    int Image::height() const {
        return height_;
    }

    Color &Image::at(int x, int y) {
        return pixels[y][x];
    }

    const Color &Image::at(int x, int y) const {
        return pixels[y][x];
    }
}
