#pragma once
#include <SDL2/SDL.h>
#include <animation.h>

typedef enum {
    IDLE,
    RUNNING,
    ATTACKING,
    DED
} PlayerState;

typedef struct {
    Animator anim;
    unsigned int curr_frame;
    int x;
    int y;
    int width;
    int height;
    float dir;
    int ammo;
    int speed;
    PlayerState state;
    SDL_Texture *sprite_sheet;
} Player;

void create_player(SDL_Renderer *renderer, int x, int y);
void next_player_frame();
void render_player(SDL_Renderer *renderer, float deltaTime);