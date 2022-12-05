#include <SDL2/SDL.h>
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

void move_puck() {
    int yMouse;
    SDL_GetMouseState(NULL, &yMouse);
    puck->loc = yMouse;
    
}

int get_puck_loc() {
    return puck->loc;
}