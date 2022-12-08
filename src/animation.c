#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define PLAYER_IDLE_PATH = "./res/images/sprites/Idle.png"

typedef struct {
    unsigned int prevTime;
    unsigned int currentTime;
    float deltaTime;
    float animTime;
} Animator;

void create_animation(SDL_Renderer *renderer){
    
}