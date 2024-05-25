// joas47

#ifndef PROJEKTHT22_BUTTON_H
#define PROJEKTHT22_BUTTON_H

#include <string>
#include "Component.h"

namespace game {
    class Button : public engine::Component {
    public:
        static Button *getInstance(int x, int y, int w, int h, const std::string &text);

        void mouseDown(const SDL_Event &) override;

        void mouseUp(const SDL_Event &) override;

        void draw() const override;

        virtual void perform(Button *source) {};

        ~Button() override;

        std::string getType() const override { return "Button"; }

        void tick() override;

    protected:
        Button(int x, int y, int w, int h, const std::string &text);

    private:
        std::string text;
        SDL_Texture *texture;
        SDL_Texture *upIcon, *downIcon;
        bool isDown = false;
    };
}

#endif //PROJEKTHT22_BUTTON_H
