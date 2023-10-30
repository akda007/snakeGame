//
// Created by akdag on 10/29/2023.
//

#include "render.h"

void printData(char c) {
    switch(c) {
        case 0:
            printf(" ");
            break;
//        case 1:
//            FOREGROUND_COLOR(0, 160, 0);
//            printf("%c", 219);
//            RESET_FOREGROUND();
//            break;
        case 1:
        case 2:
            FOREGROUND_COLOR(0, 160, 0);
            printf("%c", 254);
            RESET_FOREGROUND();
            break;
        case 3:
            FOREGROUND_COLOR(200, 0, 0);
            printf("%c", 178);
            RESET_FOREGROUND();
            break;

        default: break;
    }
}

void drawGame(Game_T *game) {
    int width = game->game_matrix->cols;

    printf("%cPoints: %-*d%c\n", 179, width-8, game->points, 179);

    printf("%c", 195);
    for (int i = 0; i < game->game_matrix->cols; i++) {
        printf("%c", 196);
    }

    printf("%c", 180);

    for (int i = 0; i < game->game_matrix->rows; i++) {
        printf("\n%c", 179);
        for (int j = 0; j < game->game_matrix->cols; j++) {
            printData(getElement(game->game_matrix, i, j));
        }
        printf("%c", 179);
    }

    printf("\n%c", 192);

    for (int i = 0; i < game->game_matrix->cols; i++) {
        printf("%c", 196);
    }

    printf("%c", 217);

    fflush(stdout);
    MOVE_HOME();
}
