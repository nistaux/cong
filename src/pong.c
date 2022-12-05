#include <stdlib.h>
#include <debug.h>
#include <rand.h>
#include <math.h>
#include <defs.h>

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

Pong *pong;

void init_pong() {
    pong = malloc(sizeof(Pong));

    // this is setting a random direction starting to the left
    float speed = 7.0;
    float xvel = get_rand_f(-speed,-(speed*0.65));
    float yvel;
    if (get_rand_f(-1.0,1.0) < 0.0){
        yvel = (speed - fabs(xvel)) * -1.0;
    }else {
        yvel = (speed - fabs(xvel));
    };

    Direction dir = {
        .x = xvel,
        .y = yvel
    };
    Coordinate start = {
        .x = (SCREEN_WIDTH/2) - (PONG_SIZE/2),
        .y = SCREEN_HEIGHT/2 - (PONG_SIZE/2)
    };
    pong -> coord = start;
    pong -> speed = speed;
    pong -> dir = dir;

    print_debug_f("init dir.x -> %f", dir.x);
    print_debug_f("init dir.y -> %f", dir.y);
}

void free_pong() {
    free(pong);
}

void move_pong() {
    pong->coord.x += pong->dir.x;
    pong->coord.y += pong->dir.y;
}

void check_pong_collision() {

    // hitting left wall
    if(pong->coord.x < 0){
        pong->dir.x = pong->dir.x * -1;
        print_debug("hit left wall");
    }

    // hitting right wall
    if((pong->coord.x + PONG_SIZE) > SCREEN_WIDTH){
        pong->dir.x = pong->dir.x * -1;
        print_debug("hit right wall");
    }

    // hitting top wall
    if(pong->coord.y < 0){
        pong->dir.y = pong->dir.y * -1;
        print_debug("hit top wall");
    }

    // hitting bottom wall
    if((pong->coord.y + PONG_SIZE) > SCREEN_HEIGHT){
        pong->dir.y = pong->dir.y * -1;
        print_debug("hit bottom wall");
    }
}

Coordinate get_pong_coords() {
    return pong->coord;
}