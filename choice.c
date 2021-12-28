#define _CRT_SECURE_NO_WARNINGS

#include "choice.h"

Choice createNewChoice(int data, bool isHit) {
    Choice choice;
    choice.data = data;
    choice.isHit = isHit;
    return choice;
}

void updateIsHit(Choice *choice, bool isHit) {
    choice->isHit = isHit;
}

bool checkIfChoiceWasHit(Choice *choice) {
    return choice->isHit;
}


Choice *getChoiceByDataFromArray(Choice *choices, int length, int data) {
    int i;
    for (i = 0; i < length; i++) {
        if (choices[i].data == data) {
            return &(choices[i]);
        }
    }
    return NULL;
}

void printChoice(Choice choice) {
    printf("data : %d ", choice.data);
    printf("isHit : %d \n", choice.isHit);
}

void printChoices(Choice *choices, int length) {
    for (int i = 0; i < length; i++) {
        printChoice(choices[i]);
    }
}

void printChoiceData(Choice choice) {
    printf(" %d ", choice.data);
}

void printChoicesData(Choice *choices, int length) {
    for (int i = 0; i < length; i++) {
        printChoiceData(choices[i]);
    }
    printf("\n");
}

bool isChoiceInArray(Choice *choiceArray, int size, Choice choice) {
    int i;
    bool isExist = false;
    for (i = 0; i < size; i++) {
        if (choiceArray[i].data == choice.data) {
            isExist = true;
        }
    }
    return isExist;
}

void manuallyFillQ(Choice **queue) {
    int i, j, tmpNumber;
    PIsNumValid *pIsNumValid = isValidChoiceNum;
    Choice *choices = (Choice *) malloc(sizeof(Choice) * SizeOfQueue);
    checkMemoryAllocation(choices);

    for (i = 0; i < SizeOfQueue; i++) {
        tmpNumber = getRandomNum(1, 15);
        while (getChoiceByDataFromArray(choices, i, tmpNumber) != NULL) {
            tmpNumber = getNumberInput(msgQChoice, errorQChoice, pIsNumValid);
        }
        choices[i] = createNewChoice(tmpNumber, false);
    }
    *queue = choices;
}

void autoFillQ(Choice **queue) {
    int i, tmpNumber;
    Choice *choices = (Choice *) malloc(sizeof(Choice) * SizeOfQueue);
    checkMemoryAllocation(choices);

    for (i = 0; i < SizeOfQueue; i++) {
        tmpNumber = getRandomNum(1, 15);
        while (getChoiceByDataFromArray(choices, i, tmpNumber) != NULL) {
            tmpNumber = getRandomNum(1, 15);
        }
        choices[i] = createNewChoice(tmpNumber, false);
    }
    *queue = choices;
}