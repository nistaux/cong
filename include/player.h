#pragma once

#include <SDL.h>

#include <sprite.h>

typedef struct Player {
    float x;
    float y;
    int health;
    int ammo;
    Sprite sprite;
} Player;

void init_player();
void free_player();
void draw_player(SDL_Renderer *renderer);