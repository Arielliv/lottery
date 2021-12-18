#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#define ExitSign 3

void showMenu() {
	int userChoice, numberOfParticipants;
	ListUsers* users;
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
		scanf("%d", userChoice);
		if (userChoice == 1) {
			numberOfParticipants = getNumerOfParticipants();
			users = setupUsersList();
		}
		else if (userChoice == 2) {
		}
		else {
			printf("wrong input - try again.\n");
		}
	}

}

int getNumerOfParticipants() {
	int numberOfParticipants = 0;
	bool isNumberValid = false;
	while (isNumberValid == false) {
		printf("Please enter number of participants\n");
		scanf("%d", numberOfParticipants);
		if (numberOfParticipants <= 0) {
			printf("number have to be bigger then 0, try again\n");
		}
		else {
			isNumberValid = true;
		}
	}
	return numberOfParticipants;

}

char* getParticipantName() {
	printf("Please enter participant name: \n");
	return getDynamicStringInput();
}

bool getIsAutoLottery() {
	int userChoice;
	bool isNumberValid = false;
	while (isNumberValid == false) {
		printf("Please choose one of the following options and enter it's number:\n"
			"1- Manual lottory\n"
			"\n"
			"2- Auto lottery\n");
		scanf("%d", userChoice);
		if (userChoice < 1 && userChoice >2) {
			printf("wrong input - try again.\n");
		}
		else {
			isNumberValid = true;
		}
	}
	if (userChoice == 1) {
		return false;
	}
	else {
		return true;
	}
}

int getNumberOfUserQs() {
	int userChoice;
	bool isNumberValid = false;
	while (isNumberValid == false) {
		printf("Please enter number of lottery queues :\n");
		scanf("%d", userChoice);
		if (userChoice <0) {
			printf("wrong input - try again.\n");
		}
		else {
			isNumberValid = true;
		}
	}
	return userChoice;
}

ListUsers* setupUsersList(int numberOfParticipants) {
	int i, numOfUserQs;
	ListUsers* users;
	ListQ* userListQs;
	char* name;
	bool isAutoLottery;

	makeEmptyUsersList(users);

	for (i = 0; i < numberOfParticipants; i++)
	{
		name = getParticipantName();
		isAutoLottery = getIsAutoLottery();
		numOfUserQs = getNumberOfUserQs();
		userListQs = createListOfUserQs(isAutoLottery);
		

	}
}

ListQ* createListOfUserQs(bool isAutoLottery) {

}