#include <stdbool.h>

#include <SDL2/SDL.h>

#include <game.h>

void handle_keypress(SDL_Event e) {
    int key = e.key.keysym.sym;

    // Controls based on current Game State
    switch (get_game()->state) {
        // INTRO Game State
        case INTRO:
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
        // Game Game State - This is when the game is actually being played
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
        // Pause Game State - This is when the game is paused
        case PAUSE:
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
        // End Game State - When the game is over
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