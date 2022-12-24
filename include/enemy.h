#pragma once

#include <SDL2/SDL.h>
#include <animation.h>

typedef enum {
    DEFAULT
} EnemyType;

typedef struct {
    EnemyType type;
    Animator anim;
    int x;
    int y;
} Enemy;

void create_enemy(SDL_Renderer *renderer, EnemyType type);