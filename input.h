#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


#define msgQChoice  "Please enter a value:\n"
#define errorQChoice "Wrong input - try again. \nChoose a unique number between 1-15.\n"
#define msgQ "Please enter desired number of lottery queues :\n"
#define errorQ  "Wrong input - try again.\n"
#define msgParticipants "Please enter the number of participants :\n"
#define errorParticipants  "Value has to be bigger than 0, try again.\n"
#define autoLottoryMsg "Please choose one of the following options by entering its number :\n1- Manual lottory\n\n2- Auto lottery\n"
#define autoLottoryError "Wrong input - try again.\n"
#define continueGameMsg "\nSo, would you like to try another round and save your results?\n 1- No\n\n 2- Yes\n"
#define continueGameError "Wrong input - try again.\n"

typedef bool (*PIsNumValid)(int);

int getNumberInput(char *msg, char *error, PIsNumValid cb);

bool getBoolInput(char *msg, char *error, PIsNumValid cb);

char *getParticipantName();

char *getDynamicStringInput();