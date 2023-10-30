//
// Created by akdag on 10/29/2023.
//

#include "SnakeDefs.h"


Snake_T *createSnake(int max_length) {
    Snake_T *snake = malloc(sizeof(Snake_T));

    snake->body = malloc(sizeof(SnakePart_T) * max_length);
    snake->length = 0;

    return snake;
}

void freeSnake(Snake_T *snake) {
    free(snake->body);
    free(snake);
}


