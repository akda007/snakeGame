//
// Created by akdag on 10/29/2023.
//

#ifndef SNAKEGAME_SNAKEMAIN_H
#define SNAKEGAME_SNAKEMAIN_H

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../utils/terminal.h"
#include "../matrix/gmatrix.h"
#include "SnakeDefs.h"
#include "snakeLogic.h"
#include "../render/render.h"



Game_T * initGame(int rows, int cols);
void freeGame(Game_T *obj);
bool runGame(Game_T *game);
void createApple(Game_T *g);


#endif //SNAKEGAME_SNAKEMAIN_H
