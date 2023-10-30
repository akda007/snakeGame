//
// Handles the game matrix
//

#ifndef SNAKEGAME_GMATRIX_H
#define SNAKEGAME_GMATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *data;
    int rows, cols;
} Matrix;

void freeMatrix(Matrix *matrix);
Matrix *createMatrix(int rows, int cols);
char getElement(Matrix *matrix, int x, int y);
void fillMatrix(Matrix *matrix, char value);
void setElement(Matrix *matrix, char value, int x, int y);

#endif //SNAKEGAME_GMATRIX_H
