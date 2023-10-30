#include <stdio.h>

#include "./game/snakeMain.h"
#include "./events/ticks.h"
#include "./utils/terminal.h"

int elapsed = 0;

void debug(void){
    printf("%d\r", ++elapsed);
    fflush(stdout);
}

int main() {
    configureTerminal();
    ERASE_ALL();

    Game_T * game;
    for(;;) {
        game = initGame(25, 50);
        ControllerConfig config = {
        100000,
        (void*)runGame,
        (void*)game,
        true
        };

        startTickController(&config);

        freeGame(game);
    }

    return 0;
}
