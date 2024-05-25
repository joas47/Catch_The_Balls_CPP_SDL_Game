// joas47

#include "FallingObject.h"
#include "System.h"
#include "Constants.h"

namespace game {

    FallingObject::FallingObject(int x, int y, int w, int h, int speed) : Component(x, y, w, h), speed(speed) {
        texture = SDL_CreateTextureFromSurface(engine::sys.get_ren(),
                                               IMG_Load((constants::gResPath + "images/RedDot.png").c_str()));
    }

    FallingObject *FallingObject::getInstance(int x, int y, int w, int h, int speed) {
        return new FallingObject(x, y, w, h, speed);
    }

    FallingObject::~FallingObject() {
        SDL_DestroyTexture(texture);
    }

    void FallingObject::draw() const {
        SDL_RenderCopy(engine::sys.get_ren(), texture, nullptr, &getRect());
    }

    void FallingObject::tick() {
        moveDown(speed);
    }

}
