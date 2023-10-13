#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

#include <global.h>

void init_player(){
    player = malloc(sizeof(*player));

    Sprite playerSprite = {

    };
    Player setup = {
        .x = 300,
        .y = 300,
        .health = 5,
        .ammo = 5,
    };
}

void free_player(){
    free(player);
}

void draw_player(SDL_Renderer *renderer){
    //printf("test2\n");
}