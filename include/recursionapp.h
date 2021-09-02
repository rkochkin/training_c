//
// Created by ksy on 01.09.2021.
//

#ifndef TRAINING_RECURSIONAPP_H
#define TRAINING_RECURSIONAPP_H

#include "environment.h"
#include "recursion.h"

app_t recursionSumApp = {.name = "recursion sum", .call = recursionSumAppCall};
app_t notRecursionSumApp = {.name = "NOT recursion sum", .call = notRecursionSumAppCall};
app_t recursionMaxApp = {.name = "recursion max", .call = recursionMaxAppCall};
app_t notRecursionMaxApp = {.name = "not recursion max", .call = notRecursionMaxAppCall};

#endif//TRAINING_RECURSIONAPP_H
