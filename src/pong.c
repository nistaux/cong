#include <stdlib.h>
#include <time.h>

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

Pong *pong;

void init_pong() {
    pong = malloc(sizeof(Pong));


}

void free_pong() {
    free(pong);
}

void check_pong_collision() {

}