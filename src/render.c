#include <SDL2/SDL.h>

#include <window.h>

SDL_Renderer *renderer;

void init_renderer(SDL_Window *window){
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor( renderer, 54, 46, 92, 255 );
}

void update_renderer(){
    SDL_RenderClear(renderer);

    // do things
}

void present_renderer(){
    SDL_RenderPresent(renderer);
}