#define _CRT_SECURE_NO_WARNINGS

#include "file.h"

void createBinaryResultsFile(ListUsers *users, Choice* winingQ) {
    BYTE *compressedData;
    int i = 0;
    User *currUser;
    FILE *fpResults;
    fpResults = fopen("lottery.bin", "wb");
    checkFile(fpResults);

    writeCountOfParticipants(fpResults, users);     // Writing the count of users
    currUser = users->head;

    while (currUser != NULL) {
        writePerUserToFile(fpResults, currUser);
        currUser = currUser->next;
    }
    compressedData = compressDataOfSingleQueue(fpResults, winingQ);
    fwrite(compressedData, sizeof(BYTE), 3, fpResults);
    fclose(fpResults);
}

void writeCountOfParticipants(FILE *fpResults, ListUsers *users) {
    int numOfUsers = 0;

    numOfUsers = getCountOfParticipants(users);
    fwrite(&numOfUsers, sizeof(int), 1, fpResults);
}

void writePerUserToFile(FILE *fpResults, User *currUser) {
    writeLettersCountToFile(fpResults, currUser);
    writeNameOfUserToFile(fpResults, currUser);
    writeNumOfQsToFile(fpResults, currUser);
    writeCompressedQueuesDataToFile(fpResults, currUser);
}

void writeLettersCountToFile(FILE *fpResults, User *currUser)    // Writing the count of letters
{
    int lettersCount = 0;
    lettersCount = getUserLettersCount(currUser);
    fwrite(&lettersCount, sizeof(int), 1, fpResults);
}

void writeNumOfQsToFile(FILE *fpResults, User *currUser)    // Writing the number of Qs
{
    int numOfQs = 0;

    numOfQs = currUser->numOfQs;
    fwrite(&numOfQs, sizeof(int), 1, fpResults);
}

void writeNameOfUserToFile(FILE *fpResults, User *currUser)    // Writing the name of the user
{
    int lettersCount = 0;
    lettersCount = getUserLettersCount(currUser);
    fwrite(currUser->name, sizeof(char) * lettersCount, 1, fpResults);
}

void writeCompressedQueuesDataToFile(FILE *fpResults, User *user) {
    LNodeQ *currQ;
    BYTE *compressedData;

    currQ = (LNodeQ *) malloc(sizeof(LNodeQ));
    checkMemoryAllocation(currQ);
    currQ = user->listQ->head;

    while (currQ != NULL) {
        compressedData = compressDataOfSingleQueue(fpResults, currQ->choices);
        fwrite(compressedData, sizeof(BYTE), 3, fpResults);
        currQ = currQ->next;
    }
}

int getUserLettersCount(User *user) {
    int res;
    res = (int) strlen(user->name);
    return res;
}

void readFile(ListUsers *users, Choice *winningQ) {
    FILE *fpResults = fopen("lottery.bin", "rb");
    checkFile(fpResults);
    users = readUsersListFromFile(fpResults);
    winningQ = readWinningQFromFile(fpResults);
    fclose(fpResults);
}

Choice *readWinningQFromFile(FILE *fpResults) {
    int i;
    int *uncompressSingleQueue;
    Choice *choices = (Choice *) malloc(sizeof(Choice) * 6);
    checkMemoryAllocation(choices);

    uncompressSingleQueue = uncompressDataOfSingleQueue(fpResults);
    for (i = 0; i < 6; i++) {
        Choice tmpChoice;
        tmpChoice.data = uncompressSingleQueue[i];
        tmpChoice.isHit = false;
        choices[i] = tmpChoice;
    }
    return choices;
}

ListUsers *readUsersListFromFile(FILE *fpResults) {
    ListUsers *users;
    User *newUser;
    int numOfUsers = 0, i;


    users = (ListUsers *) malloc(sizeof(ListUsers));
    checkMemoryAllocation(users);

    makeEmptyUsersList(users);
    numOfUsers = readNumOfUserFromFile(fpResults);
    for (i = 0; i < numOfUsers; i++) {
        newUser = createUserFromFile(fpResults);
        insertNodeToEndListUsers(users, newUser);
    }
    return users;
}

User *createUserFromFile(FILE *fpResults) {
    int numOfQ = 0, i = 0;
    User *newUser;
    ListQ *listQ;
    char *name;
    name = readNameOfUserFromFile(fpResults);
    numOfQ = readNumOfListQFromFile(fpResults);
    listQ = readListQOfUserFromFile(fpResults, numOfQ);
    newUser = createNewUser(name, listQ, 0, numOfQ, false, NULL);

    return newUser;
}

int readNumOfListQFromFile(FILE *fpResults) {
    int numOfListQ = 0;
    fread(&numOfListQ, sizeof(int), 1, fpResults);
    return numOfListQ;
}

ListQ *readListQOfUserFromFile(FILE *fpResults, int numOfQ) {
    int i = 0;
    ListQ *listQ;
    Choice *choices;

    listQ = (ListQ *) malloc(sizeof(ListQ));
    checkMemoryAllocation(listQ);

    makeEmptyListQ(listQ);

    for (i = 0; i < numOfQ; i++) {
        choices = readChoicesFromFile(fpResults);
        insertDataToEndListQ(listQ, choices, 0);
    }
    return listQ;
}

Choice *readChoicesFromFile(FILE *fpResults) {
    int i;
    int *uncompressSingleQueue;
    int data;
    int currentChoice;
    Choice *choices = (Choice *) malloc(sizeof(Choice) * 6);
    checkMemoryAllocation(choices);

    uncompressSingleQueue = uncompressDataOfSingleQueue(fpResults);
    for (i = 0; i < 6; i++) {
        Choice tmpChoice;
        tmpChoice.data = uncompressSingleQueue[i];
        tmpChoice.isHit = false;
        choices[i] = tmpChoice;
    }
    return choices;
}

int readNumOfUserFromFile(FILE *fpResults) {
    int numOfUsers = 0;
    fread(&numOfUsers, sizeof(int), 1, fpResults);
    return numOfUsers;
}

int readLettersCountToFile(FILE *fpResults) {
    int lettersCount = 0;
    fread(&lettersCount, sizeof(int), 1, fpResults);
    return lettersCount;
}

char *readNameOfUserFromFile(FILE *fpResults) {
    char *name;
    int lettersCount = 0;

    lettersCount = readLettersCountToFile(fpResults);
    name = (char *) malloc((sizeof(char) * lettersCount) + 1);
    checkMemoryAllocation(name);

    fread(name, sizeof(char), lettersCount, fpResults);
    name[lettersCount] = '\0';
    return name;
}

bool checkIfFileExists(FILE* fpResults) {
    if (fpResults == NULL) {
        printf(firstTimeMsg);
        return false;
    }
    else {
        return true;
    }
}
