#pragma once
#include <stdbool.h>

typedef enum {
    INTRO,
    TITLE,
    GAME,
    PAUSE,
    END
} State;

typedef struct {
    bool running;
    State state;
} Game;