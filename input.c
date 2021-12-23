#include "input.h"

int getNumberInput(char* msg, char* error, PIsNumValid cb) {
	int userChoice;
	bool isNumberValid = false;
	while (isNumberValid == false) {
		printf("%s", msg);

		scanf("%d", &userChoice);
		if (cb(userChoice) == false) {
			printf("%s", error);
		}
		else {
			isNumberValid = true;
		}
	}
	return userChoice;
}

bool getIsAutoLottery() {
	int userChoice;
	bool isNumberValid = false;
	while (isNumberValid == false) {
		printf("Please choose one of the following options and enter it's number :\n"
			"1- Manual lottory\n"
			"\n"
			"2- Auto lottery\n");
		scanf("%d", &userChoice);
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

char* getParticipantName() {
	printf("Please enter participant name : \n");
	return getDynamicStringInput();
}