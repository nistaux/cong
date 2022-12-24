#pragma once
#include <SDL2/SDL.h>

typedef struct Player;

void create_player(SDL_Renderer *renderer, int x, int y);
void next_player_frame();