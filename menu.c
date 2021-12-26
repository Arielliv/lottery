#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

void showMenu() {
	int userChoice = 0, numberOfParticipants;
	bool shouldContinue = false;
	ListUsers* users;
	PIsNumValid* pIsNumValid = isBiggerThenZeroNum;
	printf(welcomMsg);
	while (userChoice != ExitSign) {
		printf(userChoiceMenuMsg);
		scanf("%d", &userChoice);
		if (userChoice == 1) {
			numberOfParticipants = getNumberInput(msgParticipants, errorParticipants, isBiggerThenZeroNum);
			users = setupUsersList(numberOfParticipants);
			Choice* winningQ =  setUpUserScore(users);
			printLotteryResults(users, winningQ);
			shouldContinue = getConfirmationTocontinue();
			if(shouldContinue == true){
				createBinaryResultsFile(users);
			}
		}
		else if (userChoice == 2) {
		}
		else if (userChoice == 3) {
			return;
		}
		else {
			printf(userChoiceMenuError);
		}
	}

}

bool getConfirmationTocontinue() {
	PIsNumValid* pIsBoolNumValid = isValidBoolNum;
	bool shouldContinue = getBoolInput(continueGameMsg, continueGameError, pIsBoolNumValid);
	return shouldContinue;
}

ListUsers* setupUsersList(int numberOfParticipants) {
	int i, numOfUserQs;
	ListUsers* users;
	ListQ* userListQ;
	char* name;
	bool isAutoLottery;
	PIsNumValid* pIsNumValid = isBiggerThenZeroNum;
	PIsNumValid* pIsBoolNumValid = isValidBoolNum;

	users = (ListUsers*)malloc(sizeof(ListUsers));
	makeEmptyUsersList(users);

	for (i = 0; i < numberOfParticipants; i++)
	{
		name = getParticipantName();
		isAutoLottery = getBoolInput(autoLottoryMsg, autoLottoryError, pIsBoolNumValid);
		numOfUserQs = getNumberInput(msgQ, errorQ, pIsNumValid);
		userListQ = createListOfUserQs(isAutoLottery, numOfUserQs);
		insertDataToEndListUsers(users, name, userListQ, numOfUserQs, 0, isAutoLottery);
	}
	
	
	return users;
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