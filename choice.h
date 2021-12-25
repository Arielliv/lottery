#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "validations.h"
#include "input.h"

#define SizeOfQueue 6

typedef struct choice {
    int data;
    bool isHit;
} Choice;

Choice createNewChoice(int data, bool isHit);

void updateIsHit(Choice* choice, bool isHit);

bool checkIfChoiceWasHit(Choice choice);

Choice* getChoiceByDataFromArray(Choice* choices, int length, int data);

void freeChoicesArray(Choice* choices, int length);

void printChoice(Choice* choice);

void printChoices(Choice* choices, int length);

bool isChoiceInArray(Choice* choiceArray, int size, Choice choice);

void printChoiceData(Choice choice);

void printChoicesData(Choice* choices, int length);
void autoFillQ(Choice** queue);
void manuallyFillQ(Choice** queue);