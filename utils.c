// Shelly Srour - 316384254, Ariel Livshits - 315363366
#define _CRT_SECURE_NO_WARNINGS

#include "utils.h"

void checkFile(FILE *fp) {
    if (fp == NULL) {
        printf("Error opening File\n");
        exit(1);
    }
}

void checkMemoryAllocation(void *ptr) {
    if (ptr == NULL) {
        puts("Memory allocation error");
        exit(1);
    }
}