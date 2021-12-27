#pragma once

#include "user.h"
#include "choice.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

void createBinaryResultsFile(ListUsers* users,  ListQ* winingQ);

void writeCountOfParticipants(FILE* fpResults, ListUsers* users);

void writePerUserToFile(FILE* fpResults, User* currUser);

void writeLettersCountToFile(FILE* fpResults, User* currUser);

void writeNumOfQsToFile(FILE* fpResults, User* currUser);

void writeNameOfUserToFile(FILE* fpResults, User* currUser);

void writeCompressedQueuesDataToFile(FILE* fpResults, User* user);


BYTE* compressDataOfSingleQueue(FILE* fpResults, Choice* choices);


int getUserLettersCount(User* user);

int readNumOfUserFromFile(FILE* fpResults);

int readLettersCountToFile(FILE* fpResults);

char* readNameOfUserFromFile(FILE* fpResults);

int* uncompressDataOfSingleQueue(FILE* fpResults);

User* createUserFromFile(FILE* fpResults);
int readNumOfListQFromFile(FILE* fpResults);

ListQ* readListQOfUserFromFile(FILE* fpResults, int numOfQ);
Choice* readChoicesFromFile(FILE* fpResults);
ListUsers* readUsersListFromFile(FILE* fpResults);
Choice* readWinningQFromFile(FILE* fpResults);
void readFile(ListUsers* users, Choice* winningQ);