//
// Created by pedro on 5/9/25.
//

#ifndef CROP_HPP
#define CROP_HPP

#include "Command.hpp"
#include "Resize.hpp"

namespace prog {
    namespace command {
        // O crop é um resize até aos limites da imagem
        class Crop final : public Resize {
        public:
            Crop(int x, int y, int w, int h);

            ~Crop();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //CROP_HPP
