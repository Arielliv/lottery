#include "list.h"


void makeEmptyList(List* lst,int typeSize)
{
    lst->head = lst->tail = NULL;
    lst->elementSize = typeSize;
}

void listFree(List* lp)
{
    Node* np = lp->head;
    while (np != NULL)
    {
        Node* next = np->next;
        free(np->data);
        free(np);
        np = next;
    }
    free(lp);
}


void listPushTail(List* lp, void* val)
{
    Node* newNode = nodeCreate(val, lp->elementSize);
    if (lp->head == NULL)
    {
        lp->head = newNode;
        lp->tail = newNode;
    }
    else
    {
        lp->tail->next = newNode;
        lp->tail = newNode;
    }
}

static Node* nodeCreate(void* data, int typeSize)
{
    Node* np = malloc(sizeof(Node));
    checkMemoryAllocation(np);
    np->data = malloc(typeSize);
    checkMemoryAllocation(np->data);
    memcpy(np->data, data, typeSize);
    return np;
}

void listPushHead(List* lp, void* val)
{
    Node* newNode = nodeCreate(val, lp->elementSize);
    if (lp->head == NULL)
    {
        lp->head = newNode;
        lp->tail = newNode;
    }
    else
    {
        newNode->next = lp->head;
        lp->head = newNode;
    }
}


bool isEmptyList(List* lst)
{
    return (lst->head == NULL);
}