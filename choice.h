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

// Creates a new choice from the input
Choice createNewChoice(int data, bool isHit);

void updateIsHit(Choice *choice, bool isHit);

bool checkIfChoiceWasHit(Choice *choice);

// Seeking for a value in 'choices' that matches 'data' and returns its pointer
Choice *getChoiceByDataFromArray(Choice *choices, int length, int data);

// Bool function that checks if chice is located in the array received
bool isChoiceInArray(Choice *choiceArray, int size, Choice choice);

void printChoiceData(Choice choice);

void printChoicesData(Choice *choices, int length);

// When a user chooses automatic lottery, this function will randomly fill a queue
void autoFillQ(Choice **queue);

// This function creates new choices for a user based on manually receive input
void manuallyFillQ(Choice **queue);