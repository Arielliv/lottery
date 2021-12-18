#define _CRT_SECURE_NO_WARNINGS
#include "random.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int getRandomNum(int min, int amount) {
	srand(time(NULL));
	return (min + rand() % (amount +1));
}