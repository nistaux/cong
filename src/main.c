// sdl headers
#define SDL_MAIN_HANDLED
#include <SDL2\SDL.h>
// standard headers
#include <stdbool.h>
// my headers
#include <defs.h>

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Cong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    bool running = true;
    SDL_Event event;
    while(running == true) {
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) {
                running  = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}