#pragma once
#include <states.h>

void tick();
Game *get_game();
void init_game();
void end_game();
void set_game_state(State state);
void set_game_running(bool running);