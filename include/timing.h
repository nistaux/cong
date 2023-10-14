#pragma once

typedef struct Timer {
    int dt;
    int df;
} Timer;

typedef struct TimeManager {
    Timer master;
    Timer play;
    int last_time;
    int swap_time;
} TimeManager;

void create_timing();
void free_timing();

void update_timing();
void swap_timing();

void reset_timing_masterDT();
void reset_timing_masterDF();

int get_timing_masterDT();
int get_timing_masterDF();
int get_timing_playDT();
int get_timing_playDF();