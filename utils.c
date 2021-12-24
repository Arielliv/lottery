#include "utils.h"

void checkFile(FILE* fp) {
    if (fp == NULL) {
        printf("Error opening File\n");
        exit(1);
    }
}

void checkMemoryAllocation(void* ptr) {
    if (ptr == NULL) {
        puts("Memory allocation error");
        exit(1);
    }
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