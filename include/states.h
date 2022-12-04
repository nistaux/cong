#pragma once
#include <stdbool.h>

typedef enum {
    TITLE,
    GAME,
    END
} State;

typedef struct {
    bool running;
    State state;
} Game;