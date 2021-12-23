#pragma once
#include <stdbool.h>

#define msgQChoice  "Please enter number for your queue :\n"
#define errorQChoice "wrong number - try again between 1-15 and unique .\n"
#define msgQ "Please enter number of lottery queues :\n"
#define errorQ  "wrong input - try again.\n"
#define msgParticipants "Please enter number of participants :\n"
#define errorParticipants  "number have to be bigger then 0, try again\n"

typedef bool (*PIsNumValid)(int);

int getNumberInput(char* msg, char* error, PIsNumValid cb);
bool getIsAutoLottery();
char* getParticipantName();