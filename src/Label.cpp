// joas47

#include "Label.h"
#include "System.h"
#include <string>
#include <utility>

using namespace std;

namespace game {

    Label::Label(int x, int y, int w, int h, const std::string &text) : Component(x, y, w, h), text(text) {
        SDL_Surface *surface = TTF_RenderText_Solid(engine::sys.get_font(), text.c_str(), {0, 0, 0});
        texture = SDL_CreateTextureFromSurface(engine::sys.get_ren(), surface);
        SDL_FreeSurface(surface);
    }

    void Label::draw() const {
        SDL_RenderCopy(engine::sys.get_ren(), texture, nullptr, &getRect());
    }

    Label::~Label() {
        SDL_DestroyTexture(texture);
    }

    Label *Label::getInstance(int x, int y, int w, int h, const std::string &text) {
        return new Label(x, y, w, h, text);
    }

    void Label::tick() {


    }

    string Label::getText() const {
        return text;
    }

    void Label::setText(std::string newText) {
        text = std::move(newText);
        SDL_DestroyTexture(texture);
        SDL_Surface *surface = TTF_RenderText_Solid(engine::sys.get_font(), text.c_str(), {0, 0, 0});
        texture = SDL_CreateTextureFromSurface(engine::sys.get_ren(), surface);
        SDL_FreeSurface(surface);
    }
}