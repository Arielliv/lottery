#define _CRT_SECURE_NO_WARNINGS
#include "user.h"

void makeEmptyUsersList(ListUsers* lst) {
	lst->head = lst->tail = NULL;
}

void insertDataToEndListUsers(ListUsers* lst, char* name, ListQ* list, int numOfQs, double avarageOfHits, bool isAuto){
	User* newTail;

	newTail = createNewUser(name, list,avarageOfHits, numOfQs, isAuto, NULL);
	insertNodeToEndListUsers(lst, newTail);
}

User* createNewUser(char* name, ListQ* list, double avarageOfHits, int numOfQs, bool isAuto, User* next) {
	User* res;

	res = (User*)malloc(sizeof(User));
	res->avrageOfHits = avarageOfHits;
	res->isAuto = isAuto;
	res->name = name;
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

//int getUserTotalNumOfHits(User* user);

//void updateUserNumOfQs(int numOfQs, User* user);

//void updateUserAvarageOfHits(double avarage, User* user);

//int getUserNumOfQs(int numOfQs, User* user);

//double getUserAvarageOfHits(double avarage, User* user);

//User* getUserWithHighestScore(ListUsers* ListOfUsers);