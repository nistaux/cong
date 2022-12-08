#pragma once
#include <stdbool.h>

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

Game *get_game();
void init_game();
void end_game();
void set_game_state(State state);
void set_game_running(bool running);

void tick();