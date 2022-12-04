#pragma once

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    float x;
    float y;
} Direction;

typedef struct {
    Coordinate coord;
    int speed;
    Direction dir;
} Pong;

void init_pong();
void free_pong();
void check_pong_collision();