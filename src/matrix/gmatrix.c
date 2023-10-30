#include "gmatrix.h"

Matrix *createMatrix(int rows, int cols) {
    Matrix * matrix = malloc(sizeof(Matrix));

    if (matrix == NULL) {
        puts("Unable to create the matrix.");
        exit(-1);
    }

    matrix->data = calloc(rows * cols, sizeof(char));
    matrix->cols = cols;
    matrix->rows = rows;

    if (matrix->data == NULL) {
        puts("Unable to create the matrix.");
        exit(-1);
    }

    return matrix;
}

void fillMatrix(Matrix *matrix, char value) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            setElement(matrix, value, i, j);
        }
    }
}


void setElement(Matrix *matrix, char value, int x, int y) {
    matrix->data[x * matrix->cols + y] = value;
}

char getElement(Matrix *matrix, int x, int y) {
    return matrix->data[x * matrix->cols + y];
}

void freeMatrix(Matrix *matrix) {
    free(matrix->data);
    free(matrix);
}