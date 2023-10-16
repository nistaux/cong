#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <global.h>
#include <window.h>
#include <game.h>
#include <events.h>
#include <player.h>
#include <controller.h>
#include <ui.h>

void start_game(){
    // init memory for game
    create_window();
    create_timing();
    create_controller();
    create_ui();

    game = malloc(sizeof(*game));
    if(game == NULL){
        printf("Failed to allocate memory for game...\n");
        exit(1);
    }
    Game initialGame = {
        .prev_state = GAME_STATE_TITLE,
        .state = GAME_STATE_TITLE,
        .running = true,
    };
    *game = initialGame;
    init_player();
}

void stop_game(){
    game->running = false;
}

void end_game(){
    // free enemies - include enemy projectiles
    free_player();
    free(game);
    free_ui();
    free_controller();
    free_timing();
    free_window();
}

bool get_game_isRunning(){
    return game->running;
}

void tick_game(){
    // do ticking things
    tick_player();
    // at end reset timing tick
    reset_timing_masterDT();
}

void run_game(){
    int tps, fps;

    manage_events();

    tps = 1000/GAME_TICK_RATE;
    fps = 1000/GAME_FRAME_RATE;
    update_timing();
    
    if(time_manager->master.dt > tps)
        tick_game();
    if(time_manager->master.df > fps)
        update_window();
}