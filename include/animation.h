#pragma once

typedef struct {
    unsigned int prevTime;
    unsigned int currentTime;
    float deltaTime;
    float animTime;
} Animator;