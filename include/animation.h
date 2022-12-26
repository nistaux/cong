#pragma once

typedef struct {
    unsigned int prevTime;
    unsigned int currentTime;
    float deltaTime;
    float animTime;
    float animIter;
    int total_frames;
    int frame_diff;
} Animator;