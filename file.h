#pragma once

#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

void createBinaryResultsFile(ListUsers* users);

void writeCountOfParticipants(FILE* fpResults, ListUsers* users);

void writePerUserToFile(FILE* fpResults, User* currUser);

void writeLettersCountToFile(FILE* fpResults, User* currUser);

void writeNumOfQsToFile(FILE* fpResults, User* currUser);

void writeNameOfUserToFile(FILE* fpResults, User* currUser);

void writeCompressedQueuesDataToFile(FILE* fpResults, User* user);


BYTE* compressDataOfSingleQueue(FILE* fpResults, Choice* choices);


int getUserLettersCount(User* user);

//void printLotteryResults(FILE * results);



ListUsers* createUsersListFromFile();

//void createUserFromFile(FILE * fpResults, User* newUser);

int readNumOfUserFromFile(FILE* fpResults);

int readLettersCountToFile(FILE* fpResults);

char* readNameOfUserFromFile(FILE* fpResults);

int* uncompressDataOfSingleQueue(FILE* fpResults);

void createChoiceFromFile(int* queue);
