#pragma once
#define manual 1
#define auto 0

#include "choice.h"
#include "listQ.h"
#include "random.h"
#include "user.h"
#include "file.h"

void showMenu();

int getUserMenuSelection();

void createNewLottery();

int getNumerOfParticipants();

bool getUserLotteryType();

void printUserLotteryOptions();

void printLotteryResults();

Choice* createWinningRandomQ();

void printSortedListOfQs(listQ ListOfQs);
