#include "listQ.h"

void makeEmptyListQ(ListQ* lst)
{
	lst->head = lst->tail = NULL;
}

void insertDataToEndListQ(ListQ* lst, Choice** choices, int length, int totalCountOfHits)
{
	LNodeQ* newTail;

	newTail = createNewLNodeQ(choices, length, totalCountOfHits, NULL);
	insertNodeToEndListNode(lst, newTail);
}
void insertNodeToEndListNode(ListQ* lst, LNodeQ* newTail)
{
	if (isEmptyListQ(lst))
		lst->head = lst->tail = newTail;
	else {
		lst->tail->next = newTail;
		lst->tail = newTail;
	}
}

LNodeQ* createNewLNodeQ(Choice** choices, int length, int totalCountOfHits, LNodeQ* next)
{
	LNodeQ* res;

	res = (LNodeQ*)malloc(sizeof(LNodeQ));
	checkMemoryAllocation(res);
	res->totalCountOfHits = totalCountOfHits;
	res->choices = (Choice**)malloc(sizeof(Choice*)*length);
	checkMemoryAllocation(res->choices);
	for (int i = 0; i < length; i++) {
		res->choices[i] = choices[i];
	}
	res->next = next;
	return res;
}

bool isEmptyListQ(ListQ* lst)
{
	return (lst->head == NULL);
}

//LNodeQ* getLNodeQByChoiceData(ListQ* lst, int choiceData)
//{
//
//}


int getNumOfLNodeQByNumOfHits(ListQ* lst, int numOfHits)
{
	int counter = 0;
	LNodeQ* curr;

	curr = lst->head;
	while (curr != NULL)
	{
		if (curr->totalCountOfHits == numOfHits)
		{
			counter++;
		}
		curr = curr->next;
	}
	return counter;
}

int getLNodeQNumOfHits(LNodeQ* lNodeQ)
{
	return lNodeQ->totalCountOfHits;
}