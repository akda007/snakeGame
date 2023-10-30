//
// Created by akdag on 10/29/2023.
//

#include "snakeMain.h"

void createApple(Game_T *g) {
    srand(time(NULL));

    int x = rand() % g->game_matrix->rows;
    int y = rand() % g->game_matrix->cols;

    Apple_T apple = {x, y};

    g->apple = apple;
}


Game_T *initGame(int rows, int cols) {
    Game_T *game = malloc(sizeof(Game_T));

    game->points = 0;
    game->running = true;

    game->game_matrix = createMatrix(rows, cols);
    game->snake = createSnake(rows * cols);

    SnakePart_T head = {game->game_matrix->rows / 2, game->game_matrix->cols / 2, Right};
    game->snake->head = head;

    addSnakePart(game->snake);
    addSnakePart(game->snake);
    addSnakePart(game->snake);

    createApple(game);
    return game;
}

void freeGame(Game_T *obj) {
    freeMatrix(obj->game_matrix);
    freeSnake(obj->snake);

    free(obj);
}

bool runGame(Game_T *game) {
    if (game == NULL) {
        printf("Game not initialized!");
        exit(-1);
    }

    if (!moveSnake(game)) {
        game->running = false;
        return false;
    }

    drawGame(game);

    return true;
}
