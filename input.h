#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define msgQChoice  "Please enter number for your queue :\n"
#define errorQChoice "wrong number - try again between 1-15 and unique .\n"
#define msgQ "Please enter number of lottery queues :\n"
#define errorQ  "wrong input - try again.\n"
#define msgParticipants "Please enter number of participants :\n"
#define errorParticipants  "number have to be bigger then 0, try again\n"
#define autoLottoryMsg "Please choose one of the following options and enter it's number :\n1- Manual lottory\n\n2- Auto lottery\n"
#define autoLottoryError "wrong input - try again.\n"
#define continueGameMsg "\nSo, do you want to try another round and save your results?\n 1- No\n\n 2- Yes\n"
#define continueGameError "wrong input - try again.\n"

typedef bool (*PIsNumValid)(int);

int getNumberInput(char *msg, char *error, PIsNumValid cb);

bool getBoolInput(char *msg, char *error, PIsNumValid cb);

char *getParticipantName();

char *getDynamicStringInput();