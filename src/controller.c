#include <stdbool.h>
#include <stdio.h>

#include <global.h>
#include <controller.h>

void create_controller(){
    controller = malloc(sizeof(*controller));
    if(controller == NULL){
        printf("Failed to allocate memory for controller...\n");
        exit(1);
    }

    Controller setup = {
        .w_pressed = false,
        .a_pressed = false,
        .s_pressed = false,
        .d_pressed = false,

        .upArrow_pressed = false,
        .leftArrow_pressed = false,
        .downArrow_pressed = false,
        .rightArrow_pressed = false,

        .space_pressed = false,
        .esc_pressed = false,
    };

    *controller = setup;
}

void free_controller(){
    free(controller);
}

void controller_reset(){
    Controller reset = {
        .w_pressed = false,
        .a_pressed = false,
        .s_pressed = false,
        .d_pressed = false,

        .upArrow_pressed = false,
        .leftArrow_pressed = false,
        .downArrow_pressed = false,
        .rightArrow_pressed = false,

        .space_pressed = false,
        .esc_pressed = false,
    };

    *controller = reset;
}

void controller_toggle_w(bool pressed){
    controller->w_pressed = pressed;
}
void controller_toggle_a(bool pressed){
    controller->a_pressed = pressed;
}
void controller_toggle_s(bool pressed){
    controller->s_pressed = pressed;
}
void controller_toggle_d(bool pressed){
    controller->d_pressed = pressed;
}

void controller_toggle_space(bool pressed){
    controller->space_pressed = pressed;
}
void controller_toggle_esc(bool pressed){
    controller->esc_pressed = pressed;
}

void controller_toggle_upArrow(bool pressed){
    controller->upArrow_pressed = pressed;
}
void controller_toggle_leftArrow(bool pressed){
    controller->leftArrow_pressed = pressed;
}
void controller_toggle_downArrow(bool pressed){
    controller->downArrow_pressed = pressed;
}
void controller_toggle_rightArrow(bool pressed){
    controller->rightArrow_pressed = pressed;
}