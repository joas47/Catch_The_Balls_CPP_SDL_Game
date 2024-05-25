// joas47

#include "Player.h"
#include "System.h"
#include "Constants.h"

namespace game {

    Player::Player(int x, int y, int w, int h) : Component(x, y, w, h) {
        texture = SDL_CreateTextureFromSurface(engine::sys.get_ren(),
                                               IMG_Load((constants::gResPath + "images/BlueDot.png").c_str()));
    }

    Player *Player::getInstance(int x, int y, int w, int h) {
        return new Player(x, y, w, h);
    }

    Player::~Player() {
        SDL_DestroyTexture(texture);
    }

    void Player::draw() const {
        SDL_RenderCopy(engine::sys.get_ren(), texture, nullptr, &getRect());
    }

    void Player::tick() {
        if (getRect().x <= 0) {
            moveRight(5);
        } else if (getRect().x >= constants::getScreenWidth - getRect().w) {
            moveLeft(5);
        } else {
            moveRight(speed);
        }
    }

    void Player::keyDown(const SDL_Event &event) {
        if (event.key.keysym.sym == SDLK_LEFT) {
            speed = -10;
        } else if (event.key.keysym.sym == SDLK_RIGHT) {
            speed = 10;
        }
    }

    void Player::keyUp(const SDL_Event &event) {
        if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT) {
            speed = 0;
        }
    }

    bool Player::collidesWith(const Component *other) const {
//        return SDL_HasIntersection(&getRect(), &other->getRect());

        // collision detection
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        //Calculate the sides of rect A
        leftA = getRect().x;
        rightA = getRect().x + getRect().w;
        topA = getRect().y;
        bottomA = getRect().y + getRect().h;

        //Calculate the sides of rect B
        leftB = other->getRect().x;
        rightB = other->getRect().x + other->getRect().w;
        topB = other->getRect().y;
        bottomB = other->getRect().y + other->getRect().h;

        // If any of the sides from A are outside B
        if (bottomA <= topB) {
            return false;
        }

        if (topA >= bottomB) {
            return false;
        }

        if (rightA <= leftB) {
            return false;
        }

        if (leftA >= rightB) {
            return false;
        }

        //If none of the sides from A are outside B
        return true;
    }
}