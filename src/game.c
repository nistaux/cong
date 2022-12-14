// STD headers
#include <stdbool.h>
#include <stdlib.h>

// SDL2 headers
#include <SDL2/SDL.h>

// My headers
#include <events.h>
#include <window.h>
#include <rand.h>
#include <debug.h>
#include <player.h>

typedef enum {
    INTRO,
    TITLE,
    GAME,
    PAUSE,
    END
} State;

typedef struct {
    bool running;
    bool debug;
    State state;
} Game;

typedef struct {
    unsigned int prevTime;
    unsigned int currentTime;
    float deltaTime;
    float physicsTime;
    float physicsIter;
    float renderTime;
    float renderIter;
} Timer;

Game game;
Timer timer;
SDL_Event event;

void init_game() {

    // Setting Game Struct Init Settings
    game.running = true;
    game.state = TITLE;
    game.debug = false;

    // Setting Timer Struct Init Settings
    timer.prevTime = 0;
    timer.currentTime = 0;
    timer.deltaTime = 0.0f;
    timer.physicsTime = 0.0f;
    timer.renderTime = 0.0f;

    // Processing tick rate (60 Ticks/Sec)
    timer.physicsIter = (1.0/60.0);
    // Render set FPS (120 Frames/Sec)
    timer.renderIter = (1.0/100.0);
    init_rand();
}

void end_game() {
    //free(game);
}

Game *get_game() {
    return &game;
}

float get_timer_delta() {
    return timer.deltaTime;
}

void set_game_state(State state) {
    game.state = state;
}

void set_game_running(bool running) {
    game.running = running;
}

void tick() {
    // Getting information on current processing speed
    // and using that to set FPS and Processing rate
    timer.prevTime = timer.currentTime;
    timer.currentTime = SDL_GetTicks();
    timer.deltaTime = (timer.currentTime-timer.prevTime)/1000.0f;
    timer.physicsTime += timer.deltaTime;
    timer.renderTime += timer.deltaTime;

    if (timer.physicsIter <= timer.physicsTime) {
        timer.physicsTime = 0.0;

        // Check control input
        check_events(event);
    }
    if (timer.renderIter <= timer.renderTime) {
        timer.renderTime = 0.0;

        // render updates
        update_window();
    }
}