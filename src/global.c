#include <SDL.h>

#include <game.h>
#include <timing.h>
#include <player.h>
#include <controller.h>

SDL_Window *window;
SDL_Renderer *renderer;
Game *game;
TimeManager *time_manager;
Player *player;
Controller *controller;