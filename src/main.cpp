// joas47

#include "GameEngine.h"
#include "CatchTheBallsGame.h"

int main(int argc, char *args[]) {
    engine::GameEngine *gameEngine = engine::GameEngine::getInstance();
    game::CatchTheBallsGame *catchTheBallsGame = game::CatchTheBallsGame::getInstance(gameEngine);
    gameEngine->run(catchTheBallsGame);
    return 0;
}
