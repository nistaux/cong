// STD headers
#include <stdbool.h>

// SDL2 headers
#include <SDL2/SDL.h>

// My headers
#include <game.h>

void check_events(SDL_Event event) {
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) {
            set_game_running(false);
        }
    }
}