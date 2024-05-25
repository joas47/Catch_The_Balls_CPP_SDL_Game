// joas47

#ifndef PROJEKTHT22_GAMEENGINE_H
#define PROJEKTHT22_GAMEENGINE_H

#include <vector>
#include "Component.h"

namespace engine {

    class Game; // Forward declaration

    class GameEngine {
    public:
        static GameEngine *getInstance();

        void run(Game *game);

        void add(Component *component);

        void remove(Component *component);

        void quitGame() { quit = true; }

        void setWindowTitle(const std::string& title) const;

        ~GameEngine();

        GameEngine(const GameEngine &) = delete;

        const GameEngine &operator=(const GameEngine &) = delete;

    private:
        GameEngine();

        std::vector<Component *> components;
        std::vector<Component *> toBeRemoved;
        std::vector<Component *> toBeAdded;
        int tickCounter = 0;
        bool quit = false;

        void deleteComponents();

        void addNewComponents();

        void SDLEventLoop(SDL_Event &event);

        void draw();

        void delay(Uint32 nextTick) const;
    };
}

#endif //PROJEKTHT22_GAMEENGINE_H
