// Shelly Srour - 316384254, Ariel Livshits - 315363366
#define _CRT_SECURE_NO_WARNINGS

#include "random.h"

int getRandomNum(int min, int amount) {
    srand(time(NULL));
    return (min + rand() % (amount));
}