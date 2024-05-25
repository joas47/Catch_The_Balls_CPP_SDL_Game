// joas47

#ifndef PROJEKTHT22_CATCHTHEBALLSGAME_H
#define PROJEKTHT22_CATCHTHEBALLSGAME_H

#include <vector>
#include "Game.h"
#include "FallingObject.h"
#include "Player.h"
#include "Label.h"

namespace game {
    class CatchTheBallsGame : public engine::Game {
    public:
        static CatchTheBallsGame *getInstance(engine::GameEngine *gameEngine);

        ~CatchTheBallsGame() override;

        void gameEvent(int tickCounter) override;

        void checkCollision(std::vector<engine::Component *> components) override;

    protected:
        explicit CatchTheBallsGame(engine::GameEngine *gameEngine);

    private:

        Player *player;
        Label *scoreLabel;
        Label *levelLabel;
        Label *livesLabel;
        int level;
        int score;
        int lives;

        void gameOver();

        void increaseScore() override;

        void addFallingObject(int speed) override;

        void decreaseLife() override;

        void increaseLevel() override;

        void init(engine::GameEngine *gameEngine) override;

        void restartGame() override;
    };
}

#endif //PROJEKTHT22_CATCHTHEBALLSGAME_H
