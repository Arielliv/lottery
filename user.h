#pragma once

#include "listQ.h"
#include <stdlib.h>

typedef struct user {
	char* name;
	ListQ* listQ;
	double avrageOfHits;
	bool isAuto;
	int numOfQs;
	struct user* next;
} User;

typedef struct listUsers {
	User* head;
	User* tail;
}ListUsers;

void makeEmptyUsersList(ListUsers* lst);

void insertDataToEndListUsers(ListUsers* usersList, char* name, ListQ* listQ, int numOfQs, double avarageOfHits, bool isAuto);

User* createNewUser(char* name, ListQ* list, double avarageOfHits, int numOfQs, bool isAuto, User* next);

bool isEmptyListUsers(ListUsers* lst);

void insertNodeToEndListUsers(ListUsers* lst, User* newTail);

void setUserTotalNumOfHits(User* user, Choice* winningQueue);

void updateUserNumOfQs(int numOfQs, User* user);

void updateUserAvarageOfHits(double avarage, User* user);

int getUserNumOfQs(int numOfQs, User* user);

double getUserAvarageOfHits(double avarage, User* user);

User* getUserWithHighestScore(ListUsers* ListOfUsers);



