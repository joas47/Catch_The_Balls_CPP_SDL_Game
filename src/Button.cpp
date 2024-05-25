// joas47

#include "Button.h"
#include "System.h"
#include "Constants.h"

namespace game {

    Button::Button(int x, int y, int w, int h, const std::string &text) : Component(x, y, w, h) {
        SDL_Surface *surface = TTF_RenderText_Solid(engine::sys.get_font(), text.c_str(), {0, 0, 0});
        texture = SDL_CreateTextureFromSurface(engine::sys.get_ren(), surface);
        SDL_FreeSurface(surface);
        upIcon = IMG_LoadTexture(engine::sys.get_ren(), (constants::gResPath + "/images/UppKnapp.png").c_str());
        downIcon = IMG_LoadTexture(engine::sys.get_ren(), (constants::gResPath + "/images/NerKnapp.png").c_str());
    }

    Button *Button::getInstance(int x, int y, int w, int h, const std::string &text) {
        return new Button(x, y, w, h, text);
    }

    void Button::tick() {

    }

    void Button::draw() const {
        if (isDown) {
            SDL_RenderCopy(engine::sys.get_ren(), downIcon, nullptr, &getRect());
        } else {
            SDL_RenderCopy(engine::sys.get_ren(), upIcon, nullptr, &getRect());
        }
        SDL_RenderCopy(engine::sys.get_ren(), texture, nullptr, &getRect());
    }

    void Button::mouseDown(const SDL_Event &event) {
        SDL_Point p = {event.button.x, event.button.y};
        if (SDL_PointInRect(&p, &getRect())) {
            isDown = true;
        }
    }

    void Button::mouseUp(const SDL_Event &event) {
        SDL_Point p = {event.button.x, event.button.y};
        if (SDL_PointInRect(&p, &getRect())) {
            perform(this);
        }
        isDown = false;
    }

    Button::~Button() {
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(upIcon);
        SDL_DestroyTexture(downIcon);
    }
}