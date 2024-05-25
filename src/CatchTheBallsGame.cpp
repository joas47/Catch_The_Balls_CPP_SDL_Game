// joas47

#include "CatchTheBallsGame.h"
#include "System.h"
#include "Constants.h"
#include "Label.h"

namespace game {

    CatchTheBallsGame::CatchTheBallsGame(engine::GameEngine *gameEngine) : Game(gameEngine) {
        CatchTheBallsGame::init(gameEngine);
        gameEngine->setWindowTitle("Catch the balls!");
    }

    CatchTheBallsGame *CatchTheBallsGame::getInstance(engine::GameEngine *gameEngine) {
        return new CatchTheBallsGame(gameEngine);
    }

    void CatchTheBallsGame::gameEvent(int tickCounter) {
        // Add new FallingObject every 100 ticks
        if (tickCounter % 100 == 0) {
            // Add a new FallingObject with speed 1 + level
            addFallingObject(level + 1);
        }
    }

    void CatchTheBallsGame::addFallingObject(int speed) {
        // add new FallingObject to components at random x position
        int random = rand() % constants::getScreenWidth;
        gameEngine->add(FallingObject::getInstance(
                random, 0, constants::getFallingObjectWidth, constants::getFallingObjectHeight, speed));
    }

    void CatchTheBallsGame::init(engine::GameEngine *gameEngine) {

        // Create player and labels
        player = Player::getInstance(constants::getScreenWidth / 2,
                                     constants::getScreenHeight - constants::getPlayerHeight,
                                     constants::getPlayerWidth, constants::getPlayerHeight);
        scoreLabel = Label::getInstance(10, 10, constants::getLabelWidth, constants::getLabelHeight, "Score: 0");
        levelLabel = Label::getInstance(10, 40, constants::getLabelWidth, constants::getLabelHeight, "Level: 1");
        livesLabel = Label::getInstance(10, 70, constants::getLabelWidth, constants::getLabelHeight, "Lives: 3");
        gameEngine->add(player);
        gameEngine->add(scoreLabel);
        gameEngine->add(levelLabel);
        gameEngine->add(livesLabel);

        // Set game variables
        level = 1;
        score = 0;
        lives = 3;
    }

    CatchTheBallsGame::~CatchTheBallsGame() {
        delete player;
        delete scoreLabel;
        delete levelLabel;
        delete livesLabel;
        delete gameEngine;
    }

    void CatchTheBallsGame::checkCollision(std::vector<engine::Component *> components) {
        // Check collision between player and falling objects
        for (auto component: components) {
            if (component->getType() == "FallingObject") {
                if (player->collidesWith(component)) {
                    gameEngine->remove(component);
                    increaseScore();
                }
                    // Remove falling objects that have fallen outside the screen
                else if (component->getRect().y >= constants::getScreenHeight) {
                    gameEngine->remove(component);
                    decreaseLife();
                }
            }
        }
    }

    void CatchTheBallsGame::increaseScore() {
        score++;
        scoreLabel->setText("Score: " + std::to_string(score));
        // Increase level every 10 points
        if (score % 10 == 0) {
            increaseLevel();
        }
    }

    void CatchTheBallsGame::increaseLevel() {
        level++;
        levelLabel->setText("Level: " + std::to_string(level));
    }

    void CatchTheBallsGame::decreaseLife() {
        lives--;
        livesLabel->setText("Lives: " + std::to_string(lives));
        if (lives == 0) {
            gameOver();
        }
    }

    void CatchTheBallsGame::gameOver() {

        std::string message =
                "You reached level " + std::to_string(level) + " and scored " + std::to_string(score) + " points!";

        SDL_MessageBoxButtonData buttons[] = {
                {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Restart"},
                {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "Quit"},
        };

        SDL_MessageBoxData messageboxdata = {
                SDL_MESSAGEBOX_INFORMATION,
                nullptr,
                "Game Over",
                message.c_str(),
                SDL_arraysize(buttons),
                buttons,
                nullptr
        };

        int buttonid;
        if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
            SDL_Log("error displaying message box");
            return;
        }

        if (buttonid == -1) {
            SDL_Log("no selection");
        } else if (buttonid == 0) {
            restartGame();
        } else if (buttonid == 1) {
            gameEngine->quitGame();
        }
    }

    void CatchTheBallsGame::restartGame() {
        delete gameEngine;
        gameEngine = nullptr;
        gameEngine = engine::GameEngine::getInstance();
        init(gameEngine);
        gameEngine->run(this);
    }
}