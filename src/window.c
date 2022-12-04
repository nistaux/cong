// SDL2 headers
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

// My headers
#include <defs.h>
#include <render.h>

SDL_Window *window;

void init_sdl() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Cong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    init_renderer(window);
}

void end_sdl() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Window *get_window() {
    return window;
}

void update_window() {
   update_renderer();
   present_renderer();
}