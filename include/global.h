#pragma once

#include <SDL.h>

#include <game.h>
#include <timing.h>

#define GAME_NAME "Cong"
#define GAME_VERSION "v0.0.1.230929"

// 16x9 Resolution - 1280x720
#define GAME_WIDTH 1280
#define GAME_HEIGHT 720

#define GAME_TICK_RATE 250
#define GAME_FRAME_RATE 250

extern SDL_Window *window;
extern SDL_Renderer *renderer;

/*
STATE MANAGEMENT
- Game Master Struct
    // Game state tracking
  - STATE
    - GAME_STATE_TITLE
    - GAME_STATE_PLAY
    - GAME_STATE_MENU
    // This will contain what the previous state was
  - PREV_STATE
    // boolean of if the game is running
  - RUNNING
*/
extern Game *game;

/*
Timer
    // This is is basically going to be one for one SDL_GetTicks64()
  - Master Time
      // Total time since last tick
    - Delta Tick Time
      // Total time since last frame
    - Delta Frame Time

    // This will be the time that has passed while in play state
    // Will only be ticked on while in the play state
  - Play Time
      // Total time since last tick, while in GAME_STATE_PLAY
    - Delta Tick Time

    // This will be set any time play time is swapped to and from
    // This will allow for play time to still work even when
    // it is swapped out of so that timings dont continue to count
    // while in menus
  - swap_time
*/
extern TimeManager *time_manager;