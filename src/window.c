#include <stdio.h>

#include <global.h>

void create_window(){
    int ret;

    // Initialize SDL
    ret = SDL_Init(SDL_INIT_VIDEO);
    if(ret < 0){
        printf("SDL Error: SDL Failed to Initialize. Error Code %d", ret);
        // eventually change exit(ret) to atexit(cleanup)
        exit(ret);
        return;
    }

    // Creating SDL Window
    window = SDL_CreateWindow(
        GAME_NAME, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        GAME_WIDTH, 
        GAME_HEIGHT, 
        0
    );
    
    // Creating Renderer for the Window above
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void free_window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void update_window(){
    SDL_RenderClear(renderer);
    SDL_Rect rect = {
        .x = 20,
        .y = 20,
        .w = 200,
        .h = 200
    };
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}