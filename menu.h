#pragma once

#define manual 1
#define auto 0
#define ExitSign 3

#include <stdlib.h>
#include <stdio.h>

#include "choice.h"
#include "listQ.h"
#include "random.h"
#include "user.h"
#include "file.h"
#include "utils.h"
#include "validations.h"
#include "input.h"

void showMenu();

ListQ* createListOfUserQs(bool isAutoLottery, int numOfUserQs);

ListUsers* setupUsersList(int numberOfParticipants);

void fillUserQs(bool isAutoLottery, int numOfUserQs, ListQ* listQ);

Choice* setUpUserScore(ListUsers* users);

void raffleWinningQueue(Choice** winningQueue);

void printLotteryResults(ListUsers* users, Choice* winningQ);

