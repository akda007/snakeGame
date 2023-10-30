//
// Created by akdag on 10/29/2023.
//

#ifndef SNAKEGAME_SNAKEDEFS_H
#define SNAKEGAME_SNAKEDEFS_H

#include <stdlib.h>
#include <stdbool.h>
#include "../matrix/gmatrix.h"
#include "../utils/direction.h"

typedef struct Apple {
    int x, y;
} Apple_T;

typedef struct SnakePart {
    int x, y;
    Direction direction;
} SnakePart_T;

typedef struct Snake {
    int length;

    SnakePart_T head;
    SnakePart_T *body;
} Snake_T;

typedef struct Game {
    Matrix *game_matrix;
    Apple_T apple;
    Snake_T *snake;

    int points;
    bool running;
} Game_T;

Snake_T * createSnake(int max_length);
void freeSnake(Snake_T * snake);

#endif //SNAKEGAME_SNAKEDEFS_H
