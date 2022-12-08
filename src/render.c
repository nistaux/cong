#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <window.h>
#include <pong.h>
#include <defs.h>
#include <puck.h>
#include <game.h>

#define TITLE_BACKGROUND_PATH  "./res/images/backgrounds/tbg.png"
#define GAME_BACKGROUND_PATH   "./res/images/backgrounds/gbg.png"

typedef struct {
    SDL_Texture *tbg;
    SDL_Texture *gbg;
} Bgs;

SDL_Renderer *renderer;
Bgs *bgs;

void init_renderer(SDL_Window *window){
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    bgs = malloc(sizeof(Bgs));
    bgs->gbg = IMG_LoadTexture(renderer, GAME_BACKGROUND_PATH);
    bgs->tbg = IMG_LoadTexture(renderer, TITLE_BACKGROUND_PATH);
}

void draw_background(const char *path[]) {
    SDL_RenderClear(renderer);
    //bg = IMG_LoadTexture
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
    switch (get_game()->state)
    {
    case TITLE:
        break;
        draw_background(GAME_BACKGROUND_PATH);
    default:
        break;
    }
    
    draw_pong();
    draw_puck();
    
}

void present_renderer(){
    SDL_RenderPresent(renderer);
}