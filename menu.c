#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

void showMenu() {
	int userChoice = 0, numberOfParticipants;
	ListUsers* users;
	PIsNumValid* pIsNumValid = isBiggerThenZeroNum;
	printf("welcome to out grand lottery game !!!\n");
	while (userChoice != ExitSign) {
		printf("\n"
			"Please choose one of the following options and enter it's number:\n"
			"\n"
			"1 - choose number of participants in the lottery\n"
			"\n"
			"2 - show last lottery results\n"
			"\n"
			"3 - exit\n"
		);
		scanf("%d", &userChoice);
		if (userChoice == 1) {
			numberOfParticipants = getNumberInput(msgParticipants, errorParticipants, isBiggerThenZeroNum);
			users = setupUsersList(numberOfParticipants);
			setUpUserScore(users, numberOfParticipants);
		}
		else if (userChoice == 2) {
		}
		else if (userChoice == 3) {
			return;
		}
		else {
			printf("wrong input - try again.\n");
		}
	}

}

ListUsers* setupUsersList(int numberOfParticipants) {
	int i, numOfUserQs;
	ListUsers users;
	ListQ userListQs;
	char* name;
	bool isAutoLottery;
	PIsNumValid* pIsNumValid = isBiggerThenZeroNum;

	makeEmptyUsersList(&users);

	for (i = 0; i < numberOfParticipants; i++)
	{
		name = getParticipantName();
		isAutoLottery = getIsAutoLottery();
		numOfUserQs = getNumberInput(msgQ, errorQ, pIsNumValid);
		userListQs = createListOfUserQs(isAutoLottery, numOfUserQs);
		insertDataToEndListUsers(&users, name, &userListQs, numOfUserQs, 0, isAutoLottery);
	}
	return &users;
}

ListQ createListOfUserQs(bool isAutoLottery, int numOfUserQs) {
	int i, j, tmpNumber;
	Choice* choices = (Choice*)malloc(sizeof(Choice) * SizeOfQueue);
	checkMemoryAllocation(choices);

	ListQ listQ;
	makeEmptyListQ(&listQ);

	fillUserQs(isAutoLottery, numOfUserQs, &listQ, choices);

	return listQ;
}

void fillUserQs(bool isAutoLottery, int numOfUserQs, ListQ* listQ, Choice* choices) {
	int i, j, tmpNumber;
	PIsNumValid* pIsNumValid = isValidChoiceNum;


	for (i = 0; i < numOfUserQs; i++) {
		choices = (Choice*)calloc(SizeOfQueue, sizeof(Choice) * SizeOfQueue);
		checkMemoryAllocation(choices);
		for (j = 0; j < SizeOfQueue; j++) {
			if (isAutoLottery == true) {
				tmpNumber = getRandomNum(1, 15);
			}
			else {
				tmpNumber = getNumberInput(msgQChoice, errorQChoice, pIsNumValid);
			}


			while (getChoiceByDataFromArray(choices, j, tmpNumber) != NULL) {
				if (isAutoLottery == true) {
					tmpNumber = getRandomNum(1, 15);
				}
				else {
					tmpNumber = getNumberInput(msgQChoice, errorQChoice, pIsNumValid);
				}
			}

			choices[j] = createNewChoice(tmpNumber, false);
		}
		printf("\n user queue nuber %d \n", i);
		printChoices(choices, SizeOfQueue);
		insertDataToEndListQ(listQ, choices, SizeOfQueue, 0);
	}
}
void setUpUserScore(ListUsers* users) {
	User* curr = users->head;
	Choice* winningQueue = NULL;
	raffleWinningQueue(&winningQueue);

	while (curr != NULL) {
		setUserTotalNumOfHits(curr, winningQueue);
	}
	
}

void raffleWinningQueue(Choice** winningQueue) {
	int i, tmpNumber;
	Choice* choices = (Choice*)malloc(sizeof(Choice) * SizeOfQueue);
	checkMemoryAllocation(choices);

	for (i = 0; i < SizeOfQueue; i++) {
		tmpNumber = getRandomNum(1, 15);
		while (getChoiceByDataFromArray(choices, i, tmpNumber) != NULL) {
			tmpNumber = getRandomNum(1, 15);
		}
		choices[i] = createNewChoice(tmpNumber, false);
	}
	printf("\n winning queue %d \n", i);
	printChoices(choices, i);
	*winningQueue = choices;
}


//void printLotteryResults();

//void printSortedListOfQs(ListQ ListOfQs);