#include <stdio.h>

#include <global.h>
#include <draw.h>

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
    printf("test34\n");
    SDL_RenderClear(renderer);
    draw_game(renderer);
    SDL_RenderPresent(renderer);
}