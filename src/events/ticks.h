//
// Created by akdag on 10/29/2023.
//

#ifndef SNAKEGAME_TICKS_H
#define SNAKEGAME_TICKS_H

#include <stdbool.h>
#include <sys/time.h>
#include <stdint.h>
#include "../game/SnakeDefs.h"
#include "inputs.h"

typedef struct {
    uint64_t time;
    void (*func)(Game_T*);
    Game_T *args;

    bool enabled;
} ControllerConfig;

void startTickController(ControllerConfig *config);

#endif //SNAKEGAME_TICKS_H
