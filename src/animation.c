#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include <animation.h>
#include <timing.h>
#include <player.h>

void animate(Animation *a){
    int curTime = SDL_GetTicks64();
    
    if(curTime - a->last_frame_time >= a->frame_timing){
        if(a->cur_frame < a->total_frames)
            a->cur_frame += 1;
        else
            a->cur_frame = 0;
            
        a->last_frame_time = curTime;
    }
}

void stop_animation(Animation *a){

}