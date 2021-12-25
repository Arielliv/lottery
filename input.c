#define _CRT_SECURE_NO_WARNINGS
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

char* getDynamicStringInput() {
	char* str;
	int logSize = 0, phySize = 1;
	char c;
	str = (char*)malloc(sizeof(char) * phySize);
	checkMemoryAllocation(str);

	c = getchar();
	c = getchar();
	while (c != '\n') {
		if (logSize == phySize) {
			phySize *= 2;
			str = (char*)realloc(str, sizeof(char) * phySize);
			checkMemoryAllocation(str);
		}
		str[logSize] = c;
		logSize++;
		c = getchar();
	}
	if (logSize < phySize) {
		str = (char*)realloc(str, sizeof(char) * (logSize + 1));
		checkMemoryAllocation(str);
	}
	str[logSize] = '\0';
	return str;
}