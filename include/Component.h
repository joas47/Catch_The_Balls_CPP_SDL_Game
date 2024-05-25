// joas47

#ifndef PROJEKTHT22_COMPONENT_H
#define PROJEKTHT22_COMPONENT_H

#include <SDL2/SDL.h>
#include <string>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

namespace engine {
    class Component {
    public:
        virtual ~Component();

        virtual void mouseDown(const SDL_Event &) {}; // each component subclass will have its own mouseDown function
        virtual void mouseUp(const SDL_Event &) {}; // empty virtual function, can be overridden
        virtual void mouseDown(const int &, const int &) {};

        virtual void mouseUp(const int &, const int &) {};

        virtual void keyDown(const SDL_Event &) {};

        virtual void keyUp(const SDL_Event &) {};

        virtual void draw() const = 0; // abstract function (pure virtual function), must be overridden

        const SDL_Rect &getRect() const { return rect; }

        void moveDown(int dy) { rect.y += dy; }

        void moveRight(int dx) { rect.x += dx; }

        void moveLeft(int dx) { rect.x -= dx; }

        virtual std::string getType() const = 0;

        virtual bool collidesWith(const Component *other) const { return false; };

        virtual void tick() = 0; // TODO: call a collision check function in here. Not in the GameEngine.

        Component(const Component &) = delete; // värdesemantik förbjuds

        const Component &operator=(const Component &) = delete; // värdesemantik förbjuds
    protected:
        Component(int x, int y, int w, int h);

    private:
        SDL_Rect rect;
    };
}

#endif //PROJEKTHT22_COMPONENT_H
