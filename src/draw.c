#include <SDL.h>

#include <player.h>
#include <ui.h>

void draw_background(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 62, 137, 72, 255);
    SDL_RenderFillRect(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void draw_ui(SDL_Renderer *renderer){
    draw_ui_player_arrow(renderer);
}

void draw_game(SDL_Renderer *renderer){
    draw_background(renderer);
    draw_ui(renderer);
    draw_player(renderer);
}