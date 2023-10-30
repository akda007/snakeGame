//
// Created by akdag on 10/29/2023.
//

#ifndef SNAKEGAME_SNAKELOGIC_H
#define SNAKEGAME_SNAKELOGIC_H

#include <stdbool.h>
#include "SnakeDefs.h"
#include "snakeMain.h"

void moveBody(Snake_T *snake, int last_x, int last_y);
bool moveRight(Game_T *g);
bool moveLeft(Game_T *g);
bool moveDown(Game_T *g);
bool moveUp(Game_T *g);
void addSnakePart(Snake_T *snake);
bool moveSnake(Game_T *game);
void updateMatrix(Game_T *game);

#endif //SNAKEGAME_SNAKELOGIC_H
