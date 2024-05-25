// joas47

#ifndef PROJEKTHT22_SYSTEM_H
#define PROJEKTHT22_SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Constants.h"

namespace engine {

    class System {
    public:
        System();

        ~System();

        SDL_Renderer *get_ren() const;

        TTF_Font *get_font() const;

        void setWindowTitle(const std::string& title) const;

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
        // TODO: add audio here as well if used.
        // Mix_Chunk* musik;
    };

    extern System sys;
}


#endif //PROJEKTHT22_SYSTEM_H
