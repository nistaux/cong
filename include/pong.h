#pragma once

typedef struct {
    float x;
    float y;
} Coordinate;

typedef struct {
    float x;
    float y;
} Direction;

typedef struct {
    Coordinate coord;
    float speed;
    Direction dir;
} Pong;

void init_pong();
void free_pong();
void move_pong();
void check_pong_collision();
Coordinate get_pong_coords();