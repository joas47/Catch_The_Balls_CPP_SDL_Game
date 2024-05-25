// joas47

#include "GameEngine.h"
#include "System.h"
#include "Game.h"
#include <set>

#define FPS 80

namespace engine {

    void GameEngine::run(Game *game) {

        Uint32 tickInterval = 1000 / FPS;

        while (!quit) {
            Uint32 nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event event;
            SDLEventLoop(event);

            for (Component *component: components) {
                component->tick();
            }

            game->gameEvent(tickCounter++);

            game->checkCollision(components);

            deleteComponents();

            addNewComponents();

            draw();

            delay(nextTick);
        } // end of main loop
    }

    // Delay until next tick
    void GameEngine::delay(Uint32 nextTick) const {
        Uint32 now = SDL_GetTicks();
        if (nextTick > now) {
            SDL_Delay(nextTick - now);
        }
    }

    void GameEngine::draw() {
        SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
        SDL_RenderClear(sys.get_ren());
        for (Component *component: components) {
            component->draw();
        }
        SDL_RenderPresent(sys.get_ren());
    }

    void GameEngine::SDLEventLoop(SDL_Event &event) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                for (Component *component: components) {
                    component->mouseDown(event.button.x, event.button.y);
                }
                break;
            } else if (event.type == SDL_MOUSEBUTTONUP) {
                for (Component *component: components) {
                    component->mouseUp(event.button.x, event.button.y);
                }
                break;
            } else if (event.type == SDL_KEYDOWN) {
                for (Component *component: components) {
                    component->keyDown(event);
                }
                break;
            } else if (event.type == SDL_KEYUP) {
                for (Component *component: components) {
                    component->keyUp(event);
                }
                break;
            }
        } // end of event loop

    }

    // Iterates through the vector and adds the components that have been toBeAdded
    void GameEngine::addNewComponents() {
        for (Component *component: toBeAdded) {
            components.push_back(component);
        }
        toBeAdded.clear();
    }

    // Iterates through the vector and deletes them from memory
    void GameEngine::deleteComponents() {
        for (Component *component: toBeRemoved) {
            for (auto i = components.begin(); i != components.end();) {
                if (*i == component) {
                    delete *i;
                    i = components.erase(i);
                } else {
                    i++;
                }
            }
        }
        toBeRemoved.clear();
    }

    GameEngine::~GameEngine() {
        std::set<Component *> uniqueComponents;

        // Add all components from the vectors to the set
        uniqueComponents.insert(components.begin(), components.end());
        uniqueComponents.insert(toBeAdded.begin(), toBeAdded.end());
        uniqueComponents.insert(toBeRemoved.begin(), toBeRemoved.end());

        // Delete each unique component
        for (Component *component: uniqueComponents) {
            delete component;
            component = nullptr;
        }

        // Clear the vectors
        components.clear();
        toBeAdded.clear();
        toBeRemoved.clear();
    }

    GameEngine::GameEngine() = default;

    GameEngine *GameEngine::getInstance() {
        return new GameEngine();
    }

    void GameEngine::add(Component *component) {
        toBeAdded.push_back(component);
    }

    void GameEngine::remove(Component *component) {
        toBeRemoved.push_back(component);
    }

    void GameEngine::setWindowTitle(const std::string &title) const {
        sys.setWindowTitle(title);
    }

}