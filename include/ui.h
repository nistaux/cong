#pragma  once

#include <SDL.h>

typedef struct UI {
    SDL_Texture *texture;
    SDL_Rect arrow;
    SDL_Rect health;
    SDL_Rect score;
} UI;

void create_ui();
void free_ui();

void draw_ui_player_arrow(SDL_Renderer *renderer);
void draw_ui_player_health(SDL_Renderer *renderer, int health);
void draw_ui_game_score(SDL_Renderer *renderer, int score);