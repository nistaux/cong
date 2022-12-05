// SDL2 headers
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

// My headers
#include <defs.h>
#include <render.h>
#include <stdio.h>

SDL_Window *window;

void init_sdl() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    init_renderer(window);
}

void end_sdl() {
    SDL_DestroyRenderer(SDL_GetRenderer(window));
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