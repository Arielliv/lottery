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
			Choice* winningQ =  setUpUserScore(users);
			printLotteryResults(users, winningQ);
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
	ListQ* userListQ;
	char* name;
	bool isAutoLottery;
	PIsNumValid* pIsNumValid = isBiggerThenZeroNum;

	makeEmptyUsersList(&users);

	for (i = 0; i < numberOfParticipants; i++)
	{
		name = getParticipantName();
		isAutoLottery = getIsAutoLottery();
		numOfUserQs = getNumberInput(msgQ, errorQ, pIsNumValid);
		userListQ = createListOfUserQs(isAutoLottery, numOfUserQs);
		insertDataToEndListUsers(&users, name, userListQ, numOfUserQs, 0, isAutoLottery);
		/*printf("\n asdas");
		printUserListQ(&users);
		printf("\n asdas");*/
	}
	
	
	return &users;
}

ListQ* createListOfUserQs(bool isAutoLottery, int numOfUserQs) {
	ListQ *listQ = (ListQ*)malloc(sizeof(ListQ));
	makeEmptyListQ(listQ);

	fillUserQs(isAutoLottery, numOfUserQs, listQ);

	return listQ;
}

void fillUserQs(bool isAutoLottery, int numOfUserQs, ListQ* listQ) {
	int i;
	Choice* queue = NULL;
	for (i = 0; i < numOfUserQs; i++) {
		if (isAutoLottery == true) {
			autoFillQ(&queue);
		}
		else {
			manuallyFillQ(&queue);
		}
		insertDataToEndListQ(listQ, queue, 0);
	}
}
Choice* setUpUserScore(ListUsers* users) {
	User* curr = users->head;
	Choice* winningQueue = NULL;
	raffleWinningQueue(&winningQueue);

	while (curr != NULL) {
		setUserTotalNumOfHits(curr, winningQueue);
		updateUserAvarageOfHits(curr);
		curr = curr->next;
	}

	return winningQueue;
}

void raffleWinningQueue(Choice** winningQueue) {
	autoFillQ(winningQueue);
}


void printLotteryResults(ListUsers* users,Choice * winningQ) {
	printf("Here is the winning queue : \n");
	printChoicesData(winningQ, 6);
	
	sortUsersListQs(users);
	printUserListQ(users);

	printHighestUser(users);
}