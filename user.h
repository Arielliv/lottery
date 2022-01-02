#pragma once

#include "listQ.h"
#include <stdlib.h>

typedef struct user {
    char *name;
    ListQ *listQ;
    double avrageOfHits;
    bool isAuto;
    int numOfQs;
    struct user *next;
} User;

typedef struct listUsers {
    User *head;
    User *tail;
} ListUsers;

void makeEmptyUsersList(ListUsers *lst);

// This function creates a new user from the input received and insert it to a list
void insertDataToEndListUsers(ListUsers *usersList, char *name, ListQ *listQ, int numOfQs, double avarageOfHits,
                              bool isAuto);

User *createNewUser(char *name, ListQ *listQ, double avarageOfHits, int numOfQs, bool isAuto, User *next);

bool isEmptyListUsers(ListUsers *lst);

// Receives a user and insert it to the end of the received list
void insertNodeToEndListUsers(ListUsers *lst, User *newTail);

// Based on a queue of choices provided, which stands for the winning queue
// this function sums the count of hits a user has in his queues and updates it
void setUserTotalNumOfHits(User *user, Choice *winningQueue);

void updateUserNumOfQs(int numOfQs, User *user);

void updateUserAvarageOfHits(User *user);

// Gets a list of users and return the winner based on highest avarage of hits
User *getUserWithHighestScore(ListUsers *ListOfUsers);

void printUserListQ(ListUsers *listOfUsers);

void sortUsersListQs(ListUsers *listOfUsers);

void updateUserNumOfQs(int numOfQs, User *user);

void updateUserAvarageOfHits(User *user);

// Sums and returns the user's count of hits
int getUserTotalNumOfHits(User *user);

// Returns the count of participants in the game, according to the list of users
int getCountOfParticipants(ListUsers *lst);