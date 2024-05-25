// joas47

#ifndef PROJEKTHT22_LABEL_H
#define PROJEKTHT22_LABEL_H

#include "Component.h"
#include <string>

namespace game {
    class Label : public engine::Component {
    public:
        static Label *getInstance(int x, int y, int w, int h, const std::string &text);

        void draw() const override;

        std::string getText() const;

        std::string getType() const override { return "Label"; }

        void setText(std::string text);

        ~Label() override;

        void tick() override;

    protected:
        Label(int x, int y, int w, int h, const std::string &text);

    private:
        std::string text;
        SDL_Texture *texture;
    };
}

#endif //PROJEKTHT22_LABEL_H
