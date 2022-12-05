#include <SDL2/SDL.h>

#include <window.h>
#include <pong.h>
#include <defs.h>

SDL_Renderer *renderer;

void init_renderer(SDL_Window *window){
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
}

void draw_background() {
    SDL_SetRenderDrawColor( renderer, 54, 46, 92, 255 );
}

void draw_pong() {
    SDL_Rect r = {
        .x = get_pong_coords().x,
        .y = get_pong_coords().y,
        .w = PONG_SIZE,
        .h = PONG_SIZE
    };
    SDL_SetRenderDrawColor( renderer, 25, 25, 25, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );
}   

void update_renderer(){
    draw_background();
    SDL_RenderClear(renderer);
    draw_pong();
    // do things
}

void present_renderer(){
    SDL_RenderPresent(renderer);
}