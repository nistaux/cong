#include <SDL2/SDL.h>
#include <game.h>
#include <stdbool.h>

void handle_keypress(SDL_Event e) {
    int key = e.key.keysym.sym;
    switch (key){
    case SDLK_ESCAPE:
        set_game_running(false);
        break;
    // Add more cases for different keypresses
    default:
        break;
    }
}