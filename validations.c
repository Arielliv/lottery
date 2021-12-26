#define _CRT_SECURE_NO_WARNINGS
#include "validations.h"

bool isValidBoolNum(int num) {
	if (num >= 1 && num <=2) {
		return true;
	}
	else {
		return false;
	}
}

bool isBiggerThenZeroNum(int num) {
	if (num > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool isValidChoiceNum(int num) {
	if (num > 0 && num < 16	) {
		return true;
	}
	else {
		return false;
	}
}