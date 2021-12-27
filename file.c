#define _CRT_SECURE_NO_WARNINGS

#include "file.h"

void createBinaryResultsFile(ListUsers* users, ListQ* winingQ)
{
	BYTE* compressedData;
	int i = 0;
	User* currUser;
	FILE* fpResults;
	fpResults = fopen("lottery.bin", "wb");
	checkFile(fpResults);

	writeCountOfParticipants(fpResults, users);     // Writing the count of users 
	currUser = users->head;

	while (currUser != NULL)
	{
		writePerUserToFile(fpResults, currUser);
		currUser = currUser->next;
	}
	compressedData = compressDataOfSingleQueue(fpResults, winingQ);
	fwrite(compressedData, sizeof(BYTE), 3, fpResults);
	fclose(fpResults);
}

void writeCountOfParticipants(FILE* fpResults, ListUsers* users)
{
	int numOfUsers = 0;

	numOfUsers = getCountOfParticipants(users);
	fwrite(&numOfUsers, sizeof(int), 1, fpResults);
}

void writePerUserToFile(FILE* fpResults, User* currUser)
{
	writeLettersCountToFile(fpResults, currUser);
	writeNameOfUserToFile(fpResults, currUser);
	writeNumOfQsToFile(fpResults, currUser);
	writeCompressedQueuesDataToFile(fpResults, currUser);
}

void writeLettersCountToFile(FILE* fpResults, User* currUser)    // Writing the count of letters 
{
	int lettersCount = 0;
	lettersCount = getUserLettersCount(currUser);
	fwrite(&lettersCount, sizeof(int), 1, fpResults);
}

void writeNumOfQsToFile(FILE* fpResults, User* currUser)    // Writing the number of Qs
{
	int  numOfQs = 0;

	numOfQs = currUser->numOfQs;
	fwrite(&numOfQs, sizeof(int), 1, fpResults);
}

void writeNameOfUserToFile(FILE* fpResults, User* currUser)    // Writing the name of the user
{
	int lettersCount = 0;
	lettersCount = getUserLettersCount(currUser);
	fwrite(currUser->name, sizeof(char) * lettersCount, 1, fpResults);
}

void writeCompressedQueuesDataToFile(FILE* fpResults, User* user)
{
	LNodeQ* currQ;
	BYTE* compressedData;

	currQ = (LNodeQ*)malloc(sizeof(LNodeQ));
	checkMemoryAllocation(currQ);
	currQ = user->listQ->head;

	while (currQ != NULL)
	{
		compressedData = compressDataOfSingleQueue(fpResults, currQ->choices);
		fwrite(compressedData, sizeof(BYTE), 3, fpResults);
		currQ = currQ->next;
	}
}


BYTE* compressDataOfSingleQueue(FILE* fpResults, Choice* choices)
{
	int i, choice1 = 0, choice2 = 0, byteCounter = 0;
	BYTE mask = 0, tmp = 0;
	BYTE res[3];

	for (i = 0; i < 6; i = i + 2) // Create 3 bytes
	{
		choice1 = choices[i].data;
		choice2 = choices[i + 1].data;
		tmp = (BYTE)choice1 | mask << 4;
		tmp = (BYTE)choice2 | tmp;

		res[byteCounter] = tmp;
		byteCounter++;
	}
	return res;
}

int getUserLettersCount(User* user)
{
	int res;
	res = (int)strlen(user->name);
	return res;
}

//void printLotteryResults(FILE * results)
//{
//}



//------------------------------------------- Under Works ----------------------------------

void readFile(ListUsers* users, Choice* winningQ) {
	FILE* fpResults = fopen("lottery.bin", "rb");
	checkFile(fpResults);
	users = readUsersListFromFile(fpResults);
	winningQ = readWinningQFromFile(fpResults);
	fclose(fpResults);
}

Choice* readWinningQFromFile(FILE* fpResults) {
	int i;
	int* uncompressSingleQueue;
	Choice* choices = (Choice*)malloc(sizeof(Choice) * 6);

	uncompressSingleQueue = uncompressDataOfSingleQueue(fpResults);
	for (i = 0; i < 6; i++) {
		Choice tmpChoice;
		tmpChoice.data = uncompressSingleQueue[i];
		tmpChoice.isHit = false;
		choices[i] = tmpChoice;
	}
	return choices;
}

ListUsers* readUsersListFromFile(FILE* fpResults){
	ListUsers* users;
	User* newUser;
	int numOfUsers = 0, i;

	
	
	users = (ListUsers*)malloc(sizeof(ListUsers));
	makeEmptyUsersList(users);
	numOfUsers = readNumOfUserFromFile(fpResults);
	for ( i= 0; i < numOfUsers; i++){
		newUser = createUserFromFile(fpResults);
		insertNodeToEndListUsers(users, newUser);
	}
	return users;
}

User* createUserFromFile(FILE * fpResults)
{
	int numOfQ = 0, i = 0;
	User* newUser;
	ListQ* listQ;
	char* name;
	name = readNameOfUserFromFile(fpResults);
	numOfQ = readNumOfListQFromFile(fpResults);
	listQ = readListQOfUserFromFile(fpResults, numOfQ);
	newUser = createNewUser(name, listQ, 0, numOfQ, false, NULL);

	return newUser;
}

int readNumOfListQFromFile(FILE* fpResults) {
	int numOfListQ = 0;
	fread(&numOfListQ, sizeof(int), 1, fpResults);
	return numOfListQ;
}

ListQ* readListQOfUserFromFile(FILE* fpResults, int numOfQ) {
	int i = 0;
	ListQ* listQ;
	Choice* choices;

	listQ = (ListQ*)malloc(sizeof(ListQ));
	makeEmptyListQ(listQ);

	for ( i = 0; i < numOfQ; i++)
	{
		choices = readChoicesFromFile(fpResults);
		insertDataToEndListQ(listQ, choices, 0);
	}
	return listQ;
}

Choice* readChoicesFromFile(FILE* fpResults) {
	int i;
	int* uncompressSingleQueue;
	int data;
	int currentChoice;
	Choice* choices = (Choice*)malloc(sizeof(Choice) * 6);
	uncompressSingleQueue = uncompressDataOfSingleQueue(fpResults);
	for (i = 0; i < 6; i++) {
		Choice tmpChoice;
		tmpChoice.data = uncompressSingleQueue[i];
		tmpChoice.isHit = false;
		choices[i] = tmpChoice;
	}
	return choices;
}

int readNumOfUserFromFile(FILE* fpResults)
{
	int numOfUsers = 0;
	fread(&numOfUsers, sizeof(int), 1, fpResults);
	return numOfUsers;
}

int readLettersCountToFile(FILE* fpResults)
{
	int lettersCount = 0;
	fread(&lettersCount, sizeof(int), 1, fpResults);
	return lettersCount;
}

char* readNameOfUserFromFile(FILE* fpResults)
{
	char* name;
	int lettersCount = 0;

	lettersCount = readLettersCountToFile(fpResults);
	name = (char*)malloc((sizeof(char) * lettersCount) + 1);
	checkMemoryAllocation(name);

	fread(name, sizeof(char), lettersCount, fpResults);
	name[lettersCount] = '\0';
	return name;
}

int* uncompressDataOfSingleQueue(FILE* fpResults)
{
	int i, choice1 = 0, choice2 = 0;
	BYTE mask1 = 0xf0;      // 11110000
	BYTE mask2 = 0x0f;      // 00001111
	int res[6];
	BYTE tmp;

	for (i = 0; i < 6; i = i+ 2) // unCompress 3 bytes
	{
		fread(&tmp, sizeof(BYTE), 1, fpResults);

		choice1 = (tmp + mask1) >> 4;
		choice2 = (tmp + mask2);

		res[i] = choice1;
		res[i + 1] = choice2;
	}
	return res;
}