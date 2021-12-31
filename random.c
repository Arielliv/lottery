// Shelly Srour - 316384254, Ariel Livshits - 315363366
#define _CRT_SECURE_NO_WARNINGS

#include "random.h"

void initRandomize() {
    srand(time(NULL));
}

int getRandomNum(int min, int amount) {
    return (min + rand() % (amount));
}