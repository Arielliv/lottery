#pragma once

#include "user.h"
#include "compress.h"
#include "choice.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define firstTimeMsg "First game just started, there are no results to share yet...\n"

// Creates a Binary file to store the lottery game results
void createBinaryResultsFile(ListUsers *users, Choice *winingQ);

// Set of functions to write all required data into a binary file to store the game results:
void writeCountOfParticipants(FILE *fpResults, ListUsers *users);

void writePerUserToFile(FILE *fpResults, User *currUser);

void writeLettersCountToFile(FILE *fpResults, User *currUser);

void writeNumOfQsToFile(FILE *fpResults, User *currUser);

void writeNameOfUserToFile(FILE *fpResults, User *currUser);

void writeCompressedQueuesDataToFile(FILE *fpResults, User *user);


// Set of functions to read the data stored in a binary file contanaining a game results:
int readNumOfUserFromFile(FILE *fpResults);

int readLettersCountToFile(FILE *fpResults);

char *readNameOfUserFromFile(FILE *fpResults);

int readNumOfListQFromFile(FILE *fpResults);

ListQ *readListQOfUserFromFile(FILE *fpResults, int numOfQ);

Choice *readChoicesFromFile(FILE *fpResults);

ListUsers *readUsersListFromFile(FILE *fpResults);

Choice *readWinningQFromFile(FILE *fpResults);

void readFile(ListUsers *users, Choice *winningQ);

// Gets a user and returns the number of letter of its name
int getUserLettersCount(User *user);

// This function creates a new user and store its data according to the binary file
User *createUserFromFile(FILE *fpResults);

// Checks if it's the first game
bool checkIfFileExists(FILE *fpResults);