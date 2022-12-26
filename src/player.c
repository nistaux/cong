#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <animation.h>

#define PLAYER_IDLE_PATH = "./res/images/sprites/Idle.png"

typedef enum {
    IDLE,
    RUNNING,
    ATTACKING,
    DED
} PlayerState;

typedef struct {
    Animator anim;
    unsigned int curr_frame;
    int x;
    int y;
    int width;
    int height;
    float dir;
    int ammo;
    int speed;
    PlayerState state;
    SDL_Texture *sprite_sheet;
} Player;

Player player;

void create_player(SDL_Renderer *renderer, int x, int y){

    SDL_Surface *tsurf = IMG_Load("./res/images/sprites/Idle.png");

    Animator anim = {
        .prevTime = 0,
        .currentTime = 0,
        .deltaTime = 0.0f,
        .animTime = 0.0f,
        .animIter = 1.0/4.0,
        .total_frames = 8,
        .frame_diff = 30,
    };

    Player temp = {
        .x = x,
        .y = y,
        .width = 37,
        .height = 54,
        .curr_frame = 0,
        .anim = anim,
        .ammo = 0,
        .speed = 5,
        .state = IDLE,
        .sprite_sheet = SDL_CreateTextureFromSurface(renderer, tsurf),
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

void render_player(SDL_Renderer *renderer, float deltaTime) {
    int x_spacing = 25;
    int y_spacing = 20;
    player.anim.animTime += deltaTime;
    if(player.anim.animIter <= player.anim.animTime){
        next_player_frame();
    }
    SDL_Rect current_frame = {
        .w = player.width,
        .h = player.height,
        .x = player.curr_frame*(player.width+x_spacing),
        .y = y_spacing,
    };
    SDL_Rect location = {
        .w = player.width,
        .h = player.height,
        .x = player.x,
        .y = player.y,
    };
    SDL_RenderCopy(renderer, player.sprite_sheet, &current_frame, &location);
}