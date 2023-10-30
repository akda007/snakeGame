//
// Created by akdag on 10/29/2023.
//

#include "inputs.h"

void kbListener(Snake_T *snake){
    char c;
    if (kbhit()) {
        c = (char)getch();

        switch (c) {
            case 'w':
                if (snake->head.direction == Down)
                    return;
                snake->head.direction = Up;
                break;
            case 'a':
                if (snake->head.direction == Right)
                    return;
                snake->head.direction = Left;
                break;
            case 's':
                if (snake->head.direction == Up)
                    return;
                snake->head.direction = Down;
                break;
            case 'd':
                if (snake->head.direction == Left)
                    return;
                snake->head.direction = Right;
                break;
            default:
                break;
        }
    }
}