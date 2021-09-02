//
// Created by ksy on 01.09.2021.
//

#ifndef TRAINING_ENVIRONMENT_H
#define TRAINING_ENVIRONMENT_H

#define ENV_MAX_NAME 100

typedef int (*appCall_t)(void);

typedef struct {
    char name[ENV_MAX_NAME];
    appCall_t call;
} app_t;

int run(app_t app);

#endif//TRAINING_ENVIRONMENT_H
