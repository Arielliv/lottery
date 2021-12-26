#define _CRT_SECURE_NO_WARNINGS

#include "file.h"

void createBinaryResultsFile(ListUsers* users)
{
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

//ListUsers* createUsersListFromFile()
//{
//	ListUsers* lst;
//
//	makeEmptyUsersList(lst);
//
//	return lst;
//}

//void createUserFromFile(FILE * fpResults, User* newUser)
//{
//	int numOfQs = 0, numOfUsers = 0, i = 0;
//	User* newUser;
//	char* name;
//
//	for(i = 0; i < numOfUsers; i++)
//	{
//		name = readNameOfUserFromFile(fpResults);
//		newUser = createNewUser(name, listQ, 0, numOfQs, false, NULL);
//	}
//}

//int readNumOfUserFromFile(FILE* fpResults)
//{
//	int numOfUsers = 0;
//	fread(&numOfUsers, sizeof(int), 1, fpResults);
//	return numOfUsers;
//}
//
//int readLettersCountToFile(FILE* fpResults)
//{
//	int lettersCount = 0;
//	fread(&lettersCount, sizeof(int), 1, fpResults);
//	return lettersCount;
//}
//
//char* readNameOfUserFromFile(FILE* fpResults)
//{
//	char* name;
//	int lettersCount = 0;
//
//	lettersCount = readLettersCountToFile(fpResults);
//	fread(&name, sizeof(char), lettersCount, fpResults);
//	return name;
//}
//
//int* uncompressDataOfSingleQueue(FILE* fpResults)
//{
//	int i, choice1 = 0, choice2 = 0;
//	BYTE mask1 = 0xf0;      // 11110000
//	BYTE mask2 = 0x0f;      // 00001111
//	int res[6];
//	BYTE tmp;
//
//	for (i = 0; i <= 6; i = i+ 2) // unCompress 3 bytes
//	{
//		fread(&tmp, sizeof(BYTE), 1, fpResults);
//
//		choice1 = (tmp + mask1) >> 4;
//		choice2 = (tmp + mask2);
//
//		res[i] = choice1;
//		res[i + 1] = choice2;
//	}
//	return res;
//}
//
//void createChoiceFromFile(int* queue)
//{
//	int i = 0;
//
//	for (i = 0; i <= 6; i++)
//	{
//		Choice* choice;
//		choice->data = queue[i];
//		choice->isHit = 0;
//	}
//
//}