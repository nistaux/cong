#include <stdio.h>
#include <stdbool.h>

#include <global.h>
#include <window.h>
#include <game.h>
#include <events.h>

void start_game(){
    // init memory for game
    create_window();
    create_timing();

    game = malloc(sizeof(*game));
    Game initialGame = {
        .prev_state = GAME_STATE_TITLE,
        .state = GAME_STATE_TITLE,
        .running = true,
    };
    *game = initialGame;
}

void stop_game(){
    game->running = false;
}

void end_game(){
    // free enemies - include enemy projectiles
    // free player - include player projectiles
    free(game);
    free_timing();
    free_window();
}

bool get_game_isRunning(){
    return game->running;
}

void run_game(){
    // do the game things
    int tps, fps;
    tps = 1000/GAME_TICK_RATE;
    fps = 1000/GAME_FRAME_RATE;
    manage_events();
    update_timing();

    if(time_manager->master.dt > tps){
        time_manager->master.dt = 0;
    }
}