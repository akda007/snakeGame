#include "ticks.h"


void startTickController(ControllerConfig *config) {
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC, &start);
    while (config->enabled) {
        clock_gettime(CLOCK_MONOTONIC, &stop);

        uint64_t delta = ((stop.tv_sec - start.tv_sec) * 1000000000 + (stop.tv_nsec - start.tv_nsec)) / 1000;

        kbListener(config->args->snake);
        if (delta >= config->time) {
            clock_gettime(CLOCK_MONOTONIC, &start);

            config->func(config->args);

            if (!config->args->running)
                return;
        }
    }
}
