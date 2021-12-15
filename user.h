#pragma once

#include "listQ.h"

typedef struct user {
	char* name;
	ListQ* list;
	double avrageOfHits;
	int numOfQs;
} User;

typedef struct listUsers {
	User* head;
	User* tail;
}ListUsers;

void makeEmptyUsersList(ListUsers* lst);

void insertDataToEndListUsers(ListUsers* lst, char data);

LNodeQ* createNewUser(char* name, ListQ* list, double avarageOfHits, int numOfQs, User* next);

bool isEmptyListUsers(ListUsers* lst);

void insertNodeToEndListUsers(ListUsers* lst, User* newTail);

int getUserTotalNumOfHits(User* user);

void updateUserNumOfQs(int numOfQs, User* user);

void updateUserAvarageOfHits(double avarage, User* user);

int getUserNumOfQs(int numOfQs, User* user);

double getUserAvarageOfHits(double avarage, User* user);

User* getUserWithHighestScore(listUsers* ListOfUsers);



