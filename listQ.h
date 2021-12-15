#pragma once

#include "choice.h"

typedef struct lNodeQ {
    int totalCountOfHits;
    Choice * choices;
    struct lNodeQ* next;
} LNodeQ;

typedef struct listQ{
    LNodeQ* head;
    LNodeQ* tail;
} ListQ;

void makeEmptyListQ(ListQ* lst);

void insertDataToEndListQ(ListQ* lst, char data);

LNodeQ* createNewLNodeQ(char data, LNodeQ* next);

bool isEmptyListQ(ListQ* lst);

void insertNodeToEndListQ(LNodeQ* lNodeQ, LNodeQ* newTail);

int getNumOfLNodeQByNumOfHits(ListQ* lst, int numOfHits);

int getLNodeQNumOfHits(LNodeQ* lNodeQ);

