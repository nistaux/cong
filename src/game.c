// STD headers
#include <stdbool.h>
#include <stdlib.h>

// SDL2 headers
#include <SDL2/SDL.h>

// My headers
#include <states.h>
#include <events.h>
#include <window.h>
#include <pong.h>

Game *game;
SDL_Event event;

void init_game() {
    game = malloc(sizeof(Game));
    game->running = true;
    game->state = TITLE;
}

void end_game() {
    free(game);
    free_pong();
}

Game *get_game() {
    return game;
}

void set_game_state(State state) {
    game->running = state;
}

void set_game_running(bool running) {
    game->running = running;
}

void tick() {
    // events check
    check_events(event);

    // physics check


    // render updates
    update_window();

    // setting FPS to 60
    SDL_Delay(16);
}