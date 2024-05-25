// joas47

#ifndef PROJEKTHT22_PLAYER_H
#define PROJEKTHT22_PLAYER_H

#include "Component.h"

namespace game {
    class Player : public engine::Component {
    public:
        static Player *getInstance(int x, int y, int w, int h);

        void draw() const override;

        ~Player() override;

        void tick() override;

        std::string getType() const override { return "Player"; }

        void keyDown(const SDL_Event &event) override;

        void keyUp(const SDL_Event &event) override;

        bool collidesWith(const Component *other) const override;

    protected:
        Player(int x, int y, int w, int h);

    private:
        SDL_Texture *texture;
        int speed = 0;
    };
}

#endif //PROJEKTHT22_PLAYER_H
