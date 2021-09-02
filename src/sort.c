//
// Created by ksy on 01.09.2021.
// https://www.hackerrank.com/challenges/sorting-array-of-strings/problem


#include "sort.h"
#include "stdio.h"


static int data[] = {5, 5, 5, 5, 5, 5, 5, 5, 5};


int strategyHiLo(int a, int b) {
    return a - b;
}

int partition(int *array, int lowTarget, int highTarget, int (*strategyCmp)(int, int)) {
    int pivot = array[(highTarget + lowTarget) / 2];
    int low = lowTarget;
    int high = highTarget;
    while (1) {

        while (strategyCmp(array[low], pivot) < 0) low--;
        while (strategyCmp(array[high], pivot) > 0) high--;
        if (low >= high) return high;

        //swap
        int tmp = array[low];
        array[low] = array[high];
        array[high] = tmp;

        low--;
        high--;
    }
}

void quickSort(int *array, int low, int high, int (*strategyCmp)(int, int)) {

    if (low < high) {
        int pivot = partition(array, low, high, strategyCmp);
        quickSort(array, low, pivot, strategyCmp);
        quickSort(array, pivot + 1, high, strategyCmp);
    }
}

int qsortAppCall(void) {
    quickSort(data, 0, sizeof(data) / sizeof(int) - 1, strategyHiLo);
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        printf("%d ", data[i]);
    }
}

/////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int aLen = strlen(a);
    int bLen = strlen(b);
    int index = 0;
    while (index<aLen && index<bLen){
        if (a[index]>b[index]) return 1;
        else if (a[index]<b[index]) return -1;
        index++;
        if (index == aLen && aLen==bLen) return 0;
        if (index==aLen) return -1;
        if (index==bLen) return 1;
    }
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -lexicographic_sort(a,b);
}

int distinctCalculate(const char* a){
    int distinctCounter[26]={0};

    for (char* c = a; *c != '\0'; ++c){
        distinctCounter[*c - 'a'] = 1;
    }
    int sum=0;

    for (int i=0; i < 26; ++i){
       if (distinctCounter[i]) sum++;
    }
    return sum;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int delta = distinctCalculate(a)-distinctCalculate(b);
    if (delta==0){
        delta = lexicographic_sort(a, b);
    }
    return delta;
}

int sort_by_length(const char* a, const char* b) {
    int delta = strlen(a) - strlen(b);
    if (delta == 0){
        delta = lexicographic_sort(a, b);
    }
    return delta;
}

void swapStr(char** str1, char** str2){
    char* tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

int partitionStr(
        char** arr,
        int lowTarget,
        int highTarget, int (*cmp_func)(const char* a, const char* b)
){
    char* pivot = arr[(highTarget + lowTarget)/2];
    int low = lowTarget;
    int high = highTarget;
    while (1) {
        while (cmp_func(arr[low], pivot) < 0) low++;
        while (cmp_func(arr[high], pivot) > 0) high--;
        if (low >=high) return high;
        swapStr(&arr[low], &arr[high]);
        low++;
        high--;
    }
}

void quickSortStr(
        char** arr,
        int low,
        int high,
        int (*cmp_func)(const char* a, const char* b)
){
    if (low < high) {
        int pivot = partitionStr(arr, low, high, cmp_func);
        quickSortStr(arr, low, pivot, cmp_func);
        quickSortStr(arr, pivot + 1, high, cmp_func);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    quickSortStr(arr, 0 , len-1, cmp_func);
}

int qsortStringAppCall(void){
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");


    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        printf("%d\n", distinctCalculate(arr[i]));
    }
    printf("\n");
}