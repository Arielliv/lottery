#pragma once
#include <stdio.h>
#include "choice.h"
#include "utils.h"

typedef struct lNodeQ {
	int totalCountOfHits;
	Choice* choices;
	struct lNodeQ* next;
} LNodeQ;

typedef struct listQ {
	LNodeQ* head;
	LNodeQ* tail;
} ListQ;

void makeEmptyListQ(ListQ* lst);

void insertDataToEndListQ(ListQ* lst, Choice* choices, int totalCountOfHits);

void insertNodeToEndListNode(ListQ* lst, LNodeQ* newTail);

LNodeQ* createNewLNodeQ(Choice* choices, int totalCountOfHits, LNodeQ* next);

bool isEmptyListQ(ListQ* lst);

void insertNodeToEndListQ(ListQ* lst, LNodeQ* newTail);

int getNumOfLNodeQByNumOfHits(ListQ* lst, int numOfHits);

int getLNodeQNumOfHits(LNodeQ* lNodeQ);
void updateLNodetotalOfHits(LNodeQ* lNodeQ, int totalNum);
void sortListQ(ListQ* lst);
void bubbleSort(ListQ* lst);
void swap(LNodeQ* a, LNodeQ* b);
void printListQ(ListQ* lst);