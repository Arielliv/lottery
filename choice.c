#define _CRT_SECURE_NO_WARNINGS

#include "choice.h"

Choice* createNewChoice(int data, bool isHit) {
	Choice* choice= (Choice*)malloc(sizeof(Choice));
	choice->data = data;
	choice->isHit = isHit;
}

void updateIsHit(Choice* choice, bool isHit) {
	choice->isHit = isHit;
}

bool checkIfChoiceWasHit(Choice* choice) {
	return choice->isHit;
}


Choice* getChoiceByDataFromArray(Choice** choices, int length, int data) {
	int i;
	for (i = 0; i < length; i++) {
		if (choices[i]->data == data) {
			return choices[i];
		}
	}
	return NULL;
}

void printChoice(Choice* choice) {
	printf("data : %d ", choice->data);
	printf("isHit : %d \n", choice->isHit);
}

void printChoices(Choice** choices, int length) {
	for (int i = 0; i < length; i++) {
		printChoice(choices[i]);
	}
}