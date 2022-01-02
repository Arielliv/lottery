#pragma once

#define manual 1
#define auto 0
#define ExitSign 3

#define welcomMsg "Welcome to our grand lottery game !!!\n"
#define userChoiceMenuMsg "\nPlease choose one of the following options and enter its number:\n\n1 - choose number of participants in the lottery\n\n2 - show last lottery results\n\n3 - exit\n"
#define userChoiceMenuError "Wrong input - try again.\n"

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

// Creates a list of queues
ListQ *createListOfUserQs(bool isAutoLottery, int numOfUserQs);

// Gets a number of participants and creates a new list of users for it
ListUsers *setupUsersList(int numberOfParticipants);

// Fills the queues according to his choice to do it manually or automatic
void fillUserQs(bool isAutoLottery, int numOfUserQs, ListQ *listQ);

// Builds a winning queue and returns its pointer
Choice *getWinningQueuqe();

void setUpUserScore(ListUsers *users, Choice *winningQueue);

// Raffles the values of a winning queue to compare game's results to
void raffleWinningQueue(Choice **winningQueue);

void printLotteryResults(ListUsers *users, Choice *winningQ);

// Asks the user if he would like to continue the game
bool getConfirmationTocontinue();