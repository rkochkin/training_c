//
// Created by ksy on 01.09.2021.
//

#include "stdio.h"
#include "environment.h"
#include "time.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int run(app_t app){
    int retVal=0;
    struct timespec tsBegin, tsEnd;

    printf(ANSI_COLOR_MAGENTA "\n--------------------------\nRun app: %s" ANSI_COLOR_RESET, app.name);
    printf(ANSI_COLOR_GREEN "\n--- start  ---\n" ANSI_COLOR_RESET);
    timespec_get(&tsBegin, TIME_UTC);

    retVal = app.call();

    timespec_get(&tsEnd, TIME_UTC);
    printf(ANSI_COLOR_GREEN "\n--- finish ---\n"  ANSI_COLOR_RESET);

    printf(ANSI_COLOR_BLUE "Run time: %ld nSec\n",tsEnd.tv_nsec - tsBegin.tv_nsec);

//    char buff[100];
//    strftime(buff, sizeof buff, "%D %T", gmtime(&tsBegin.tv_sec));
//    printf("Current time: %s.%09ld UTC\n", buff, tsBegin.tv_nsec);

    return retVal;
}