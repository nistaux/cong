#include <global.h>

void create_timing(){
    time_manager = malloc(sizeof(*time_manager));

    Timer initialTimer = {
        .df = 0,
        .dt = 0
    };

    // setting everything to 0
    time_manager->master = initialTimer;
    time_manager->play = initialTimer;
    time_manager->swap_time = 0;
}

void free_timing(){
    free(time_manager);
}

void update_timing(){
    int curr_time;
    
    curr_time = SDL_GetTicks64();
    if(game->state == GAME_STATE_PLAY){
        time_manager->play.dt += (curr_time - time_manager->last_time);
        time_manager->play.df += (curr_time - time_manager->last_time);
    }
    time_manager->master.dt += (curr_time - time_manager->last_time);
    time_manager->master.df += (curr_time - time_manager->last_time);
    time_manager->last_time = curr_time;
}

void swap_timing(){

}

int get_timing_masterDT(){
    return time_manager->master.dt;
}

int get_timing_masterDF(){
    return time_manager->master.df;
}

int get_timing_playDT(){
    return time_manager->play.dt;
}

int get_timing_playDF(){
    return time_manager->play.df;
}