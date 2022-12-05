#pragma once

typedef struct {
    int loc;
} Puck;

#define PUCK_WIDTH  20
#define PUCK_HEIGHT 100

void init_puck();
void free_puck();
void move_puck();
int get_puck_loc();