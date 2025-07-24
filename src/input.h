#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// enuminator
#include "enum.h"

int read_mode_value(){
    //const buffer
    char input[100];
    int value;

    // get inputVj;
    scanf("%s", input);

    //check input
    if(strlen(input) != 1 || input[0] - '0' > MAX_MODE_ENTRY || input[0] - '0' < 1){
        printf("invalid input\n");
        return 0;
    }

    //chat to int
    value = input[0] - '0';

    return value;
}


int read_value(){
    //const buffer
    char input[100];
    int value;

    // get inputVj;
    scanf("%s", input);

    //check test input
    // if(strcmp(input, "TEST_ABOBA_228") == 0){
    //     printf("test input detected\n");
    //     return TEST_INPUT_OPTION;
    // }


    //check input
    if(strlen(input) != 1 || input[0] - '0' > MAX_OPTION_ENTRY || input[0] - '0' < 1){
        printf("Invalid input\n");
        return 0;
    }

    //chat to int
    value = input[0] - '0';

    return value;
}


int digits_only(const char *s) {
    if (*s == '\0') {
        return 1;
    }

    while (*s != '\0') {
        if (!isdigit(*s)) {
            return 1;
        }
        s++;
    }

    return 0;
}


int get_array_size(){
    char size[80];

    printf("\nEnter size value\n");
    scanf("%s", size);

    if (digits_only(size) != 0){
        printf("Invalid input\n");
        return -1;
    }

    if (atoi(size) < 1){
        printf("Size must be > 0\n");
        return -1;
    }

    return atoi(size);
}


void info(){
    // entry options
    printf("\nEnter the value to the corresponding action\n");
    printf("1 : add event\n");
    printf("2 : save event sequence to file\n");
    printf("3 : peek element\n");
    printf("4 : pop element\n");
    printf("5 : exit\n");
    printf("6 : delete binary\n");
    printf("7 : find element\n\n");
}

#endif // INPUT_H