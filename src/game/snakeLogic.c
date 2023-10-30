#include "snakeLogic.h"


void moveBody(Snake_T *snake, int last_x, int last_y) {

    for (int i = 0; i < snake->length; i++){
        int hlast_x = last_x, hlast_y = last_y;

        last_x = snake->body[i].x;
        last_y = snake->body[i].y;

        snake->body[i].x = hlast_x;
        snake->body[i].y = hlast_y;
    }

}


bool moveRight(Game_T *g) {

    Snake_T *snake = g->snake;

    if (snake->head.y + 1 > g->game_matrix->cols-1) {
        return false;
    }

    int last_x = snake->head.x, last_y = snake->head.y;
    snake->head.y++;

    moveBody(snake, last_x, last_y);

    return true;
}


bool moveLeft(Game_T *g) {

    Snake_T *snake = g->snake;

    if (snake->head.y - 1 < 0) {
        return false;
    }

    int last_x = snake->head.x, last_y = snake->head.y;
    snake->head.y--;

    moveBody(snake, last_x, last_y);

    return true;
}


bool moveDown(Game_T *g) {
    Snake_T *snake = g->snake;

    if (snake->head.x + 1 > g->game_matrix->rows - 1) {
        return false;
    }

    int last_x = snake->head.x, last_y = snake->head.y;
    snake->head.x++;

    moveBody(snake, last_x, last_y);

    return true;
}


bool moveUp(Game_T *g) {
    Snake_T *snake = g->snake;


    if (snake->head.x - 1 < 0) {
        return false;
    }

    int last_x = snake->head.x, last_y = snake->head.y;
    snake->head.x--;

    moveBody(snake, last_x, last_y);

    return true;
}

bool hitHandler(Game_T *game) {
    if (getElement(game->game_matrix, game->snake->head.x, game->snake->head.y) == 1) {
        return true;
    }

    return false;
}


void addSnakePart(Snake_T *snake) {
    SnakePart_T part;
    SnakePart_T *last = snake->length > 0 ? &(snake->body[snake->length-1]) : &(snake->head);

    switch (last->direction) {
        case Up:
            part.x = last->x + 1;
            part.y = last->y;
            part.direction = last->direction;
            break;
        case Down:
            part.x = last->x - 1;
            part.y = last->y;
            part.direction = last->direction;
            break;
        case Left:
            part.x = last->x;
            part.y = last->y+1;
            part.direction = last->direction;
            break;
        case Right:
            part.x = last->x;
            part.y = last->y - 1;
            part.direction = last->direction;
            break;
    }

    snake->body[snake->length] = part;
    snake->length++;
}

void appleHandler(Game_T *game) {
    if (game->apple.x == game->snake->head.x && game->apple.y == game->snake->head.y) {
        game->points++;

        createApple(game);
        addSnakePart(game->snake);
    }
}

bool moveSnake(Game_T *game) {
    bool ret = false;
    switch (game->snake->head.direction) {
        case Up:
            ret = moveUp(game);
            break;
        case Down:
            ret = moveDown(game);
            break;
        case Left:
            ret = moveLeft(game);
            break;
        case Right:
            ret = moveRight(game);
            break;
    }

    appleHandler(game);
    updateMatrix(game);

    return ret && !hitHandler(game);
}

void updateMatrix(Game_T *game) {
    fillMatrix(game->game_matrix, 0);

    setElement(game->game_matrix, 3, game->apple.x, game->apple.y);
    setElement(game->game_matrix, 2, game->snake->head.x, game->snake->head.y);

    for (int i = 0; i < game->snake->length; ++i) {
        setElement(game->game_matrix, 1, game->snake->body[i].x, game->snake->body[i].y);
    }

}
