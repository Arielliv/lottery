#define _CRT_SECURE_NO_WARNINGS
#include "user.h"

void makeEmptyUsersList(ListUsers* lst) {
	lst->head = lst->tail = NULL;
}

void insertDataToEndListUsers(ListUsers* usersList, char* name, ListQ* listQ, int numOfQs, double avarageOfHits, bool isAuto){
	User* newTail;

	newTail = createNewUser(name, listQ,avarageOfHits, numOfQs, isAuto, NULL);
	insertNodeToEndListUsers(usersList, newTail);
}

User* createNewUser(char* name, ListQ* list, double avarageOfHits, int numOfQs, bool isAuto, User* next) {
	User* res;

	res = (User*)malloc(sizeof(User));
	checkMemoryAllocation(res);

	res->avrageOfHits = avarageOfHits;
	res->isAuto = isAuto;
	res->name = name;
	res->listQ = list;
	res->numOfQs = numOfQs;
	res->next = next;

	return res;
}

bool isEmptyListUsers(ListUsers* lst) {
	if (lst->head == NULL) {
		return true;
	}
	else {
		return false;
	}
		
}

void insertNodeToEndListUsers(ListUsers* lst, User* newTail) {
	if (isEmptyListUsers(lst)) {
		lst->head = lst->tail = newTail;
	}
	else {
		lst->tail->next = newTail;
		lst->tail = newTail;
	}
}

void setUserTotalNumOfHits(User* user, Choice* winningQueue) {
	
	LNodeQ* curr = user->listQ->head;
	int i,j;
	bool isExist = false;
	int totalNumOfHits = 0;

	while(curr != NULL){
		totalNumOfHits = 0;
		for (j = 0; j < 6; j++) {
			isExist = isChoiceInArray(winningQueue, 6, &curr->choices[j]);
			if (isExist == true) {
				updateIsHit(curr, true);
				totalNumOfHits++;
			}
			else {
				updateIsHit(curr, false);
			}
		}
		updateLNodetotalOfHits(curr, totalNumOfHits);
	}

}

//void updateUserNumOfQs(int numOfQs, User* user);

//void updateUserAvarageOfHits(double avarage, User* user);

//int getUserNumOfQs(int numOfQs, User* user);

//double getUserAvarageOfHits(double avarage, User* user);

//User* getUserWithHighestScore(ListUsers* ListOfUsers);