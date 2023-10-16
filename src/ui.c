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

double get_mouse_angle(int centerPlayer_x, int centerPlayer_y){
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    double rise = centerPlayer_y-mouseY;
    double run = centerPlayer_x-mouseX;

    // when run is negative, on right side of player
    // when rise is negative, on bottom side of player
    // if rise is positive and run is negative - in 1st quadrant
    bool quad_one = (rise >= 0.0 && run >= 0.0);
    // if rise is positive and run is negative - in 2nd quadrant
    bool quad_two = (rise >= 0.0 && run <= 0.0);
    // if rise is negative and run is positive - in 3rd quadrant
    bool quad_three = (rise <= 0.0 && run <= 0.0);
    // if rise is negative and run is negative - in 4th quadrant
    bool quad_four = (rise <= 0.0 && run >= 0.0);
    double slope = (fabs(rise))/(fabs(run));
    double slopeRadians = atan2(fabs(rise), fabs(run));
    double slopeDegrees = slopeRadians * 180 / M_PI;
    double mouseAngle = 0.0;
    if(quad_one){
        mouseAngle = 180.0 + slopeDegrees;
    }else if(quad_two){
        mouseAngle = 270.0 + (90-slopeDegrees);
    }else if(quad_three){
        mouseAngle = slopeDegrees;
    }else if(quad_four){
        mouseAngle = 90.0 + (90-slopeDegrees);
    }else{
        printf("this shouldn't happen...\nRISE: %3.f\nRUN: %3.f\n", rise, run);
    }
    
    return mouseAngle;
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

    double mouseAngle = get_mouse_angle(centerPlayer_x, centerPlayer_y);
    ret = SDL_RenderCopyEx(renderer, ui->texture, &ui->arrow, &dest, mouseAngle, NULL, SDL_FLIP_NONE);
    if(ret != 0){
        printf("SDL Error: Could not render Arrow UI texture to renderer\n");
        exit(2);
    }
}

void draw_ui_player_health(SDL_Renderer *renderer, int health){

}

void draw_ui_player_score(SDL_Renderer *renderer){

}