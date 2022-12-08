#pragma once
#include <SDL2/SDL.h>

void init_ui(SDL_Renderer *renderer);

void draw_intro(SDL_Renderer *renderer);
void draw_title(SDL_Renderer *renderer);
void draw_game(SDL_Renderer *renderer);
void draw_pause(SDL_Renderer *renderer);
void draw_end(SDL_Renderer *renderer);

void draw_debug(SDL_Renderer *renderer);