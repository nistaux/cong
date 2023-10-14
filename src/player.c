#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include <SDL.h>
#include <SDL_image.h>

#include <player.h>
#include <global.h>
#include <animation.h>
#include <controller.h>

#define SPRITE_LOCATION_PLAYER "./assets/images/samurai.png"

void init_player(){
    player = malloc(sizeof(*player));
    if(player == NULL){
        printf("Failed to allocate memory for player...\n");
        exit(1);
    }

    Animation idleAnim = {
        .cur_frame = 0,
        .frame_timing = 250,
        .last_frame_time = 0,
        .total_frames = 3
    };
    Animation runAnim = {
        .cur_frame = 0,
        .frame_timing = 90,
        .last_frame_time = 0,
        .total_frames = 6
    };
    Animation attackAnim = {
        .cur_frame = 0,
        .frame_timing = 0,
        .last_frame_time = 0,
        .total_frames = 1
    };
    SDL_Rect rect = {
        .h = 32,
        .w = 32,
        .x = 0,
        .y = 0
    };

    SDL_Texture *playerText = IMG_LoadTexture(renderer, SPRITE_LOCATION_PLAYER);
    if(playerText == NULL){
        printf("SDL-Image Error: Failed to load PlayerTexture\n");
        exit(2);
    }

    Player setup = {
        // starting location
        .x = 300.0f,
        .y = 300.0f,
        .speed = 0.8f,
        .default_direction = true,

        // starting health and ammo
        .health = 5,
        .ammo = 5,

        // setting up sprite
        .state = PLAYER_STATE_IDLE,
        .sprite_sheet = playerText,
        .sprite_rect = rect,

        // setting up animations
        .attack_animation = attackAnim,
        .idle_animation = idleAnim,
        .running_animation = runAnim,
        .current_animation = idleAnim
    };

    *player = setup;
}

void set_player_state(PlayerState state){
    player->state = state;
    switch(state){
    case PLAYER_STATE_IDLE:
        player->sprite_rect.y = 0;
        player->current_animation = player->idle_animation;
        break;
    case PLAYER_STATE_RUNNING:
        player->sprite_rect.y = player->sprite_rect.h;
        player->current_animation = player->running_animation;
        break;
    case PLAYER_STATE_ATTACKING:
        player->sprite_rect.y = player->sprite_rect.h * 2;
        player->current_animation = player->attack_animation;
        break;
    default:
        break;
    }
}

void free_player(){
    // this will eventually need to free projectiles from player as well
    SDL_DestroyTexture(player->sprite_sheet);
    free(player);
}

void move_player(){
    bool no_movement_pressed = (!controller->w_pressed && !controller->a_pressed && !controller->s_pressed && !controller->d_pressed);
    if((controller->a_pressed && controller->d_pressed) || (controller->w_pressed && controller->s_pressed))
        no_movement_pressed = true;
    if(no_movement_pressed && player->state == PLAYER_STATE_IDLE) return;
    if(no_movement_pressed && player->state != PLAYER_STATE_IDLE){
        set_player_state(PLAYER_STATE_IDLE);
        return;
    }

    if(player->state != PLAYER_STATE_RUNNING) set_player_state(PLAYER_STATE_RUNNING);
    if(controller->a_pressed && !controller->d_pressed){
        player->default_direction = false;
        player->x -= player->speed;

    }
    if(controller->d_pressed && !controller->a_pressed){
        player->default_direction = true;
        player->x += player->speed;
    }
}

void tick_player(){
    move_player();
    animate(&player->current_animation);
}

void draw_player(){
    int ret;
    SDL_Rect dst = {
        .w = player->sprite_rect.w,
        .h = player->sprite_rect.h,
        .x = ((int)round(player->x)),
        .y = ((int)round(player->y)),
    };
    player->sprite_rect.x = player->current_animation.cur_frame * player->sprite_rect.w;
    if(player->default_direction){
        ret = SDL_RenderCopy(renderer, player->sprite_sheet, &player->sprite_rect, &dst);
        if(ret != 0){
            printf("SDL Error: Could not render player texture to renderer\n");
            exit(2);
        }
    }else {
        ret = SDL_RenderCopyEx(renderer, player->sprite_sheet, &player->sprite_rect, &dst, 0, NULL, SDL_FLIP_HORIZONTAL);
        if(ret != 0){
            printf("SDL Error: Could not render flipped player texture to renderer\n");
            exit(2);
        }
    }
    
}