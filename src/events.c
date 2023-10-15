#include <stdbool.h>

#include <SDL.h>

#include <game.h>
#include <controller.h>

void handle_keypress_controller(SDL_Event event){
    int key = event.key.keysym.sym;

    switch(key){
    case SDLK_ESCAPE:
        if(event.type == SDL_KEYDOWN)
            controller_toggle_esc(true);
        else
            controller_toggle_esc(false);
        break;
    case SDLK_SPACE:
        if(event.type == SDL_KEYDOWN)
            controller_toggle_space(true);
        else
            controller_toggle_space(false);
        break;
    case SDLK_w:
        if(event.type == SDL_KEYDOWN)
            controller_toggle_w(true);
        else
            controller_toggle_w(false);
        break;
    case SDLK_a:
        if(event.type == SDL_KEYDOWN)
            controller_toggle_a(true);
        else
            controller_toggle_a(false);
        break;
    case SDLK_s:
        if(event.type == SDL_KEYDOWN)
            controller_toggle_s(true);
        else
            controller_toggle_s(false);
        break;
    case SDLK_d:
        if(event.type == SDL_KEYDOWN)
            controller_toggle_d(true);
        else
            controller_toggle_d(false);
        break;
    default:
        break;
    }
}

void manage_events(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT)
            stop_game();
        if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) 
            stop_game();
        
        if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP){
            handle_keypress_controller(event);
        }
    }
}