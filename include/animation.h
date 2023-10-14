#pragma once

#include <SDL.h>

// how do I want to setup the different sprite animations
    // aka: idle, running, attacking
typedef struct Animation {
    int frame_timing; // frame speed
    int last_frame_time; // last time a frame was changed
    int total_frames; // total frames in this animation
    int cur_frame; // the current frame in animation
} Animation;

/*
 This steps through each of the processes to
 animate a sprite sheet.
*/
void animate(Animation *a);

/*
  This clears the current frame of the animation
  and sets it back to defaults.
*/
void stop_animation(Animation *a);