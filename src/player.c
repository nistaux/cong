#include <SDL2/SDL.h>
#include <animation.h>

#define PLAYER_IDLE_PATH = "./res/images/sprites/Idle.png"

typedef enum {
    IDLE,
    RUNNING,
    ATTACKING,
    DED
} State;

typedef struct {
    Animator anim;
    unsigned int curr_frame;
    int x;
    int y;
    float dir;
    int ammo;
    int speed;
    State state;
} Player;

Player player;

void create_player(SDL_Renderer *renderer, int x, int y){

    Animator anim = {
        .prevTime = 0,
        .currentTime = 0,
        .deltaTime = 0.0f,
        .animTime = 1.0/4.0,
        .total_frames = 8,
        .frame_diff = 30,
    };

    Player temp = {
        .x = x,
        .y = y,
        .curr_frame = 0,
        .dir = 0.0f,
        .anim = anim,
        .ammo = 0,
        .speed = 5,
        .state = IDLE
    };

    player = temp;
}

void next_player_frame() {
    if(player.curr_frame == 5){
        player.curr_frame = 0;
    }else{
        player.curr_frame++;
    }
}