#include <SDL2/SDL.h>
#include <game.h>
#include <stdbool.h>

void handle_keypress(SDL_Event e) {
    int key = e.key.keysym.sym;

    // Controls based on current Game State
    switch (get_game()->state) {
        // Title Game State
        case TITLE:
            switch (key) {
                // Esc Key
                case SDLK_ESCAPE:
                    set_game_running(false);
                    break;
                // Add more cases for different keypresses
                default:
                    break;
            }
            break;
        case GAME:
            switch (key) {
                // Esc Key
                case SDLK_ESCAPE:
                    set_game_running(false);
                    break;
                // Add more cases for different keypresses
                default:
                    break;
            }
            break;
        case END:
            switch (key) {
                // Esc Key
                case SDLK_ESCAPE:
                    set_game_running(false);
                    break;
                // Add more cases for different keypresses
                default:
                    break;
            }
            break;
        default:
            break;
    }
}