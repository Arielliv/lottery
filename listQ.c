#define _CRT_SECURE_NO_WARNINGS

#include "listQ.h"

void makeEmptyListQ(ListQ *lst) {
    lst->head = lst->tail = NULL;
}

void insertDataToEndListQ(ListQ *lst, Choice *choices, int totalCountOfHits) {
    LNodeQ *newTail;

    newTail = createNewLNodeQ(choices, totalCountOfHits, NULL);
    insertNodeToEndListNode(lst, newTail);
}

void insertNodeToEndListNode(ListQ *lst, LNodeQ *newTail) {
    if (isEmptyListQ(lst))
        lst->head = lst->tail = newTail;
    else {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}

LNodeQ *createNewLNodeQ(Choice *choices, int totalCountOfHits, LNodeQ *next) {
    LNodeQ *res;

    res = (LNodeQ *) malloc(sizeof(LNodeQ));
    checkMemoryAllocation(res);

    res->totalCountOfHits = totalCountOfHits;
    res->choices = choices;
    res->next = next;
    return res;
}

bool isEmptyListQ(ListQ *lst) {
    return (lst->head == NULL);
}

void printListQ(ListQ *lst) {
    if (lst == NULL) {
        return;
    }
    LNodeQ *currLNodeQ = lst->head;
    while (currLNodeQ != NULL) {
        printf("Total number of hits : %d \n", currLNodeQ->totalCountOfHits);
        printChoicesData(currLNodeQ->choices, 6);
        currLNodeQ = currLNodeQ->next;
    }
}


int getNumOfLNodeQByNumOfHits(ListQ *lst, int numOfHits) {
    int counter = 0;
    LNodeQ *curr;

    curr = lst->head;
    while (curr != NULL) {
        if (curr->totalCountOfHits == numOfHits) {
            counter++;
        }
        curr = curr->next;
    }
    return counter;
}

int getLNodeQNumOfHits(LNodeQ *lNodeQ) {
    return lNodeQ->totalCountOfHits;
}

void updateLNodetotalOfHits(LNodeQ *lNodeQ, int totalNum) {
    lNodeQ->totalCountOfHits = totalNum;
}

void sortListQ(ListQ *lst) {
    bubbleSort(lst);
}

void bubbleSort(ListQ *lst) {
    bool swapped;
    LNodeQ *curr;
    LNodeQ *next = NULL;

    if (lst == NULL)
        return;

    do {
        swapped = false;
        curr = lst->head;

        while (curr->next != next) {
            if (curr->totalCountOfHits < curr->next->totalCountOfHits) {
                swap(curr, curr->next);
                swapped = true;
            }
            curr = curr->next;
        }
        next = curr;
    } while (swapped);
}

/* function to swap data of two LNodeQ a and b*/
void swap(LNodeQ *a, LNodeQ *b) {
    Choice *tmpChoices = a->choices;
    int tmpTotalCountOfHits = a->totalCountOfHits;
    a->choices = b->choices;
    a->totalCountOfHits = b->totalCountOfHits;
    b->choices = tmpChoices;
    b->totalCountOfHits = tmpTotalCountOfHits;
}

void freeListQ(ListQ* listQ) {
    if (listQ == NULL) {
        return;
    }

    LNodeQ* currentQ = listQ->head;
    while (currentQ != NULL) {
        free(currentQ->choices);

        LNodeQ* tmpQ = currentQ;
        currentQ = currentQ->next;
        free(tmpQ);
    }
    free(listQ);
}
