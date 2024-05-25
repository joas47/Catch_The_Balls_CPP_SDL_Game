// joas47

#ifndef PROJEKTHT22_FALLINGOBJECT_H
#define PROJEKTHT22_FALLINGOBJECT_H

#include "Component.h"

namespace game {
    class FallingObject : public engine::Component {
    public:
        static FallingObject *getInstance(int x, int y, int w, int h, int speed);

        void draw() const override;

        ~FallingObject() override;

        void tick() override;

        std::string getType() const override { return "FallingObject"; }

    protected:
        FallingObject(int x, int y, int w, int h, int speed);

    private:
        SDL_Texture *texture;
        int speed;
    };
}

#endif //PROJEKTHT22_FALLINGOBJECT_H
