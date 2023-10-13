#pragma once

typedef enum SPRITE_TYPE{
    SPRITE_TYPE_PLAYER,
    SPRITE_TYPE_ENEMY
} SPRITE_TYPE;

// how do I want to setup the different sprite animations
    // aka: idle, running, attacking
typedef struct Sprite {
    SDL_Texture *sheet;
    int frame_timing;
    int last_frame_time;
    int total_frames;
    int cur_frame;
} Sprite;

Sprite create_sprite(SPRITE_TYPE type, int frame_timing);