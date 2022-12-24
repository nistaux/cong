#include <SDL2/SDL.h>
#include <animation.h>

typedef struct {
    Animator anim;
    unsigned int curr_frame;
    int x;
    int y;
    float dir;
} Player;

Player player;

void create_player(SDL_Renderer *renderer, int x, int y){
    player.x = x;
    player.y = y;
    player.curr_frame = 0;
    player.dir = 0;
}

void next_player_frame() {
    if(player.curr_frame == 5){
        player.curr_frame = 0;
    }else{
        player.curr_frame++;
    }
}