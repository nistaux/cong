#pragma once
#include <stdbool.h>

typedef enum {
    GAME_STATE_TITLE,
    GAME_STATE_MENU,
    GAME_STATE_PLAY
} GameState;

typedef struct Game {
    GameState state;
    GameState prev_state;
    bool running;
} Game;

void start_game();
bool get_game_isRunning();
void run_game();
void stop_game();
void end_game();