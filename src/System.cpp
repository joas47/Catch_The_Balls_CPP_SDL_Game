// joas47

#include "System.h"
#include <SDL2/SDL.h>
#include "Constants.h"

namespace engine {

    System::System() {
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("temp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  constants::getScreenWidth, constants::getScreenHeight, 0);
        renderer = SDL_CreateRenderer(window, -1, 0);
        TTF_Init();
        // TODO: init audio here as well?
        // Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
        // musik = Mix_LoadWAV( (constants::gResPath + "sounds/bgMusic.wav").c_str() );
        // Mix_PlayChannel(-1, musik, -1);
        font = TTF_OpenFont((constants::gResPath + "/fonts/arial.ttf").c_str(), 36);
    }

    System::~System() {
        // TODO: close audio here as well if used.
//        Mix_FreeChunk(musik);
//        Mix_CloseAudio();
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    SDL_Renderer *System::get_ren() const {
        return renderer;
    }

    TTF_Font *System::get_font() const {
        return font;
    }

    void System::setWindowTitle(const std::string& title) const {
        SDL_SetWindowTitle(window, title.c_str());
    }

    System sys;
}