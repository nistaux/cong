#include <SDL.h>
#include <game.h>

void manage_events(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT)
            stop_game();
        else if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) 
            stop_game();
    }
}