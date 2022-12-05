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
#include <rand.h>
#include <puck.h>
#include <debug.h>

typedef struct {
    unsigned int prevTime;
    unsigned int currentTime;
    float deltaTime;
    float physicsTime;
    float physicsIter;
    float renderTime;
    float renderIter;
} Timer;

Game *game;
Timer *timer;
SDL_Event event;

void init_game() {
    game = malloc(sizeof(Game));
    game->running = true;
    game->state = TITLE;

    timer = malloc(sizeof(Timer));
    timer->prevTime = 0;
    timer->currentTime = 0;
    timer->deltaTime = 0.0f;
    timer->physicsTime = 0.0f;
    timer->renderTime = 0.0f;

    // physics set tick rate (60 Ticks/Sec)
    timer->physicsIter = (1.0/60.0);
    // render set frame rate (120 Frames/Sec)
    timer->renderIter = (1.0/120.0);
    

    init_pong();
    init_rand();
    init_puck();
}

void end_game() {
    free(game);
    free_pong();
    free_puck();
}

Game *get_game() {
    return game;
}

void set_game_state(State state) {
    game->state = state;
}

void set_game_running(bool running) {
    game->running = running;
}

void tick() {
    timer->prevTime = timer->currentTime;
    timer->currentTime = SDL_GetTicks();
    timer->deltaTime = (timer->currentTime-timer->prevTime)/1000.0f;
    timer->physicsTime += timer->deltaTime;
    timer->renderTime += timer->deltaTime;

    //print_debug_f("physicsTime - %f", timer->physicsTime);
    //print_debug_f("renderTime - %f", timer->renderTime);

    if (timer->physicsIter <= timer->physicsTime) {
        timer->physicsTime = 0.0;

        check_events(event);
        check_pong_collision();
        move_puck(); 
        move_pong();
    }
    if (timer->renderIter <= timer->renderTime) {
        timer->renderTime = 0.0;
        // render updates
        update_window();
    }
}