#include <SDL2/SDL.h>

#include <window.h>
#include <pong.h>
#include <defs.h>
#include <puck.h>

SDL_Renderer *renderer;

void init_renderer(SDL_Window *window){
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
}

void draw_background() {
    SDL_SetRenderDrawColor( renderer, 54, 46, 92, 255 );
    SDL_RenderClear(renderer);
}

void draw_pong() {
    SDL_Rect r = {
        .x = get_pong_coords().x,
        .y = get_pong_coords().y,
        .w = PONG_SIZE,
        .h = PONG_SIZE
    };
    SDL_SetRenderDrawColor( renderer, 120, 120, 120, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );
    
}

void draw_puck() {
    SDL_Rect r = {
        .x = 5,
        .y = get_puck_loc()-(PUCK_HEIGHT/2),
        .w = PUCK_WIDTH,
        .h = PUCK_HEIGHT
    };
    SDL_SetRenderDrawColor( renderer, 10, 10, 10, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );
    
}


void update_renderer(){
    draw_background(); 
    draw_pong();
    draw_puck();
    
}

void present_renderer(){
    SDL_RenderPresent(renderer);
}