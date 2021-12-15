#pragma once
#include <stdbool.h>

typedef struct choice {
    int data;
    bool isHit;
} Choice;

void updateIsHit(Choice* choice, bool isHit);

bool checkIfChoiceWasHit(Choice* choice);

