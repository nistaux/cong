#pragma once

#include <stdbool.h>

#include <SDL.h>

#include <animation.h>

typedef enum {
    PLAYER_STATE_IDLE,
    PLAYER_STATE_RUNNING,
    PLAYER_STATE_ATTACKING
} PlayerState;

typedef struct Player {
    float x;
    float y;
    float speed;
    int health;
    int ammo;
    double angleToArrow;
    bool default_direction; // facing right
    SDL_Rect sprite_rect;
    SDL_Texture *sprite_sheet;
    Animation idle_animation;
    Animation running_animation;
    Animation attack_animation;
    Animation current_animation;
    PlayerState state;
} Player;

void init_player();
void free_player();

void tick_player();
void draw_player();