//
// Created by ksy on 01.09.2021.
//

#ifndef TRAINING_SORTAPP_H
#define TRAINING_SORTAPP_H

#include "environment.h"
#include "sort.h"

const app_t qsortApp = {
        .name = "quick sort",
        .call = qsortAppCall
};

const app_t qsortStringApp = {
        .name = "quick sort string",
        .call = qsortStringAppCall
};

#endif//TRAINING_SORTAPP_H
