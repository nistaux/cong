#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <window.h>
#include <defs.h>
#include <game.h>
#include <ui.h>

SDL_Renderer *renderer;

void init_renderer(SDL_Window *window){
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer != NULL){
        init_ui(renderer);
    }else {
        printf("SDL: Error Creating Renderer - %s", SDL_GetError());
    }
}

void update_renderer(){
    switch (get_game()->state) {
        case INTRO:
            draw_intro(renderer);
            break;
        case TITLE:
            draw_title(renderer);
            break;
        case GAME:
            draw_game(renderer);
            break;
        case PAUSE:
            draw_pause(renderer);
            break;
        case END:
            draw_end(renderer);
            break;
        default:
            break;
    }
    
}

void present_renderer(){
    SDL_RenderPresent(renderer);
}