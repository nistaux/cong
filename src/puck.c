#include <stdlib.h>
#include <defs.h>

typedef struct {
    int loc;
} Puck;

Puck *puck;

void init_puck() {
    puck = malloc(sizeof(Puck));
    puck->loc = SCREEN_HEIGHT/2;
}

void free_puck() {
    free(puck);
}

void set_puck_pos(int loc) {
    puck->loc = loc;
}