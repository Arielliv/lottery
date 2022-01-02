#pragma once

#include <stdio.h>
#include "choice.h"
#include "utils.h"

typedef struct lNodeQ {
    int totalCountOfHits;
    Choice *choices;
    struct lNodeQ *next;
} LNodeQ;

typedef struct listQ {
    LNodeQ *head;
    LNodeQ *tail;
} ListQ;

// Creates an empty list
void makeEmptyListQ(ListQ *lst);

// Creates a new LNodeQ from the data received and
// insert that to the end of the  list
void insertDataToEndListQ(ListQ *lst, Choice *choices, int totalCountOfHits);

// Inserts the new LNodeQ provided to the end of the list
void insertNodeToEndListNode(ListQ *lst, LNodeQ *newTail);

LNodeQ *createNewLNodeQ(Choice *choices, int totalCountOfHits, LNodeQ *next);

// Checks if the list is empty
bool isEmptyListQ(ListQ *lst);

// Returns the count of LNodeQs that has a matching number of hits to the input
int getNumOfLNodeQByNumOfHits(ListQ *lst, int numOfHits);

// Returns the number of hits of the received LNodesQ
int getLNodeQNumOfHits(LNodeQ *lNodeQ);

void updateLNodetotalOfHits(LNodeQ *lNodeQ, int totalNum);

void sortListQ(ListQ *lst);

void bubbleSort(ListQ *lst);

// This functions swaps data of LNodeQ a and LNodeQ b
void swap(LNodeQ *a, LNodeQ *b);

void printListQ(ListQ *lst);

void freeListQ(ListQ *listQ);