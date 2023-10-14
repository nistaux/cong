#pragma once

#include <stdbool.h>

typedef struct Controller {
    bool w_pressed;
    bool a_pressed;
    bool s_pressed;
    bool d_pressed;

    bool upArrow_pressed;
    bool leftArrow_pressed;
    bool downArrow_pressed;
    bool rightArrow_pressed;

    bool space_pressed;
    bool esc_pressed;
} Controller;

void create_controller();
void free_controller();

void controller_reset();

void controller_toggle_w(bool pressed);
void controller_toggle_a(bool pressed);
void controller_toggle_s(bool pressed);
void controller_toggle_d(bool pressed);

void controller_toggle_space(bool pressed);
void controller_toggle_esc(bool pressed);

void controller_toggle_upArrow(bool pressed);
void controller_toggle_leftArrow(bool pressed);
void controller_toggle_downArrow(bool pressed);
void controller_toggle_rightArrow(bool pressed);