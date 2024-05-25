// joas47

#ifndef PROJEKTHT22_GAME_H
#define PROJEKTHT22_GAME_H

#include "Component.h"
#include "GameEngine.h"

namespace engine {

//    class GameEngine; // Forward declaration

    class Game {
    public:

        virtual ~Game();

        virtual void gameEvent(int tickCounter) = 0;

        virtual void checkCollision(std::vector<Component *> vector) = 0;

        Game(const Game &) = delete;

        const Game &operator=(const Game &) = delete;

    protected:
        explicit Game(GameEngine *gameEngine); // Marked explicit to avoid implicit conversions

        GameEngine *gameEngine;

    private:

        virtual void increaseScore() = 0;

        virtual void addFallingObject(int speed) = 0;

        virtual void decreaseLife() = 0;

        virtual void increaseLevel() = 0;

        virtual void restartGame() = 0;

        virtual void init(GameEngine *gameEngine) = 0;

    };

}

#endif //PROJEKTHT22_GAME_H
