#pragma once

typedef struct {
    int loc;
} Puck;

void init_puck();
void free_puck();
void set_puck_pos(int y);