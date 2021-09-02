//
// Created by ksy on 01.09.2021.
//

#include "recursion.h"
#include "stdio.h"

static const int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23,
                   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23,
                   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23};

static long int recursionSum(const int* arr, int num) {
    if (num == 0) {
        return 0;
    } else {
        return arr[0] + recursionSum(arr + 1, num - 1);
    }
}

static int recursionMax(const int* arr, int num){
    if (num == 0){
        return 0;
    } else {
        int tileMax = recursionMax(arr + 1, num -1);
        return arr[0] > tileMax ? arr[0] : tileMax;
    }
}


// Interface
int recursionSumAppCall(void) {
    printf("sum: %ld", recursionSum(data, sizeof(data) / sizeof(int)));
}

int notRecursionSumAppCall(void) {
    long int sum = 0;
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        sum += data[i];
    }
    printf("sum: %ld", sum);
}

int recursionMaxAppCall(void) {
    printf("max: %d", recursionMax(data, sizeof(data) / sizeof(int)));
}

int notRecursionMaxAppCall(void) {
    int max = 0;
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        max = max>data[i]? max : data[i];
    }
    printf("max: %d", max);
}