#include <stdio.h>
#include <stdbool.h>

#include <game.h>

int main () {
    start_game();
    while(get_game_isRunning()) 
        run_game();
    end_game();
    return 0;
}