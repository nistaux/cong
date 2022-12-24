#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define TITLE_BACKGROUND_PATH  "./res/images/backgrounds/tbg.png"
#define GAME_BACKGROUND_PATH   "./res/images/backgrounds/gbg.png"

typedef struct {
    SDL_Texture *title_bg_img;
    SDL_Texture *game_bg_img;
} UI;

UI ui;

void init_ui(SDL_Renderer *renderer) {
    // Loading in TITLE BACKGROUND 

    /* Will be implemented later

    ui.title_bg_img = IMG_LoadTexture(renderer, TITLE_BACKGROUND_PATH);
    if (ui.title_bg_img == NULL) {
        printf("SDL: Error Loading Image - %s\n", SDL_GetError());
    } 
    */

    // Loading in GAME BACKGROUND
    ui.game_bg_img = IMG_LoadTexture(renderer, GAME_BACKGROUND_PATH);
    if (ui.game_bg_img == NULL) {
        printf("SDL: Error Loading Image - %s\n", SDL_GetError());
    } 
}

// Drawing INTRO
void draw_intro(SDL_Renderer *renderer) {

}

// Drawing TITLE
void draw_title(SDL_Renderer *renderer) {
    if (SDL_RenderClear(renderer) == 0) {

        // Rendering Background
        if(SDL_RenderCopy(renderer, ui.game_bg_img, NULL, NULL) != 0) {
            printf("SDL: Error Rendering Image - %s\n", SDL_GetError());
        }
    }else {
        printf("SDL: Error Clearing Renderer - %s\n", SDL_GetError());
    }
}

// Drawing GAME
void draw_game(SDL_Renderer *renderer) {
    if (SDL_RenderClear(renderer) == 0) {

        // Rendering Background
        if(SDL_RenderCopy(renderer, ui.game_bg_img, NULL, NULL) != 0) {
            printf("SDL: Error Rendering Image - %s\n", SDL_GetError());
        }

        // Other stuff to draw on this frame
        
    }else {
        printf("SDL: Error Clearing Renderer - %s\n", SDL_GetError());
    }
}

// Drawing PAUSE
void draw_pause(SDL_Renderer *renderer) {

}

// Drawing END
void draw_end(SDL_Renderer *renderer) {

}

// Drawing DEBUG INFO
void draw_debug(SDL_Renderer *renderer) {
    
}