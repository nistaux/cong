#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include <SDL.h>
#include <SDL_image.h>

#include <global.h>
#include <ui.h>

#define SPRITE_LOCATION_UI "./assets/images/ui.png"

void create_ui(){
    ui = malloc(sizeof(*ui));
    if(ui == NULL){
        printf("Failed to allocate memory for ui...\n");
        exit(1);
    }

    ui->texture = IMG_LoadTexture(renderer, SPRITE_LOCATION_UI);
    if(ui->texture == NULL){
        printf("SDL-Image Error: Failed to load UI Texture\n");
        exit(2);
    }

    SDL_Rect arrow = {
        .w = 50,
        .h = 50,
        .x = 0,
        .y = 0
    };
    ui->arrow = arrow;

    SDL_Rect health = {
        .w = 50,
        .h = 50,
        .x = 0,
        .y = 0
    };
    ui->health = health;

    SDL_Rect score = {
        .w = 50,
        .h = 50,
        .x = 0,
        .y = 0
    };
    ui->score = score;
}

void free_ui(){
    SDL_DestroyTexture(ui->texture);
    free(ui);
}

void draw_ui_player_arrow(SDL_Renderer *renderer){
    int ret;
    int centerPlayer_x = round(player->x) + (player->sprite_rect.w/2);
    int centerPlayer_y = round(player->y) + (player->sprite_rect.h/2);
    SDL_Rect dest = {
        .h = 50,
        .w = 50,
        .x = centerPlayer_x - (ui->arrow.w/2),
        .y = centerPlayer_y - (ui->arrow.h/2)
    };

    ret = SDL_RenderCopyEx(renderer, ui->texture, &ui->arrow, &dest, player->angleToArrow, NULL, SDL_FLIP_NONE);
    if(ret != 0){
        printf("SDL Error: Could not render Arrow UI texture to renderer\n");
        exit(2);
    }
}

void draw_ui_player_health(SDL_Renderer *renderer, int health){

}

void draw_ui_player_score(SDL_Renderer *renderer){

}