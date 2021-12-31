// Shelly Srour - 316384254, Ariel Livshits - 315363366
#define _CRT_SECURE_NO_WARNINGS

#include "user.h"

void makeEmptyUsersList(ListUsers *lst) {
    lst->head = lst->tail = NULL;
}

void insertDataToEndListUsers(ListUsers *usersList, char *name, ListQ *listQ, int numOfQs, double avarageOfHits,
                              bool isAuto) {
    User *newTail;

    newTail = createNewUser(name, listQ, avarageOfHits, numOfQs, isAuto, NULL);
    insertNodeToEndListUsers(usersList, newTail);
}

User *createNewUser(char *name, ListQ *listQ, double avarageOfHits, int numOfQs, bool isAuto, User *next) {
    User *res;

    res = (User *) malloc(sizeof(User));
    checkMemoryAllocation(res);

    res->avrageOfHits = avarageOfHits;
    res->isAuto = isAuto;
    res->name = name;
    res->listQ = listQ;
    res->numOfQs = numOfQs;
    res->next = next;

    return res;
}

bool isEmptyListUsers(ListUsers *lst) {
    if (lst->head == NULL) {
        return true;
    } else {
        return false;
    }

}

void insertNodeToEndListUsers(ListUsers *lst, User *newTail) {
    if (isEmptyListUsers(lst)) {
        lst->head = lst->tail = newTail;
    } else {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}

void setUserTotalNumOfHits(User *user, Choice *winningQueue) {

    LNodeQ *currLNodeQ = user->listQ->head;
    int i, j;
    bool isExist = false;
    int totalNumOfHits = 0;

    while (currLNodeQ != NULL) {
        totalNumOfHits = 0;
        for (j = 0; j < 6; j++) {
            isExist = isChoiceInArray(winningQueue, 6, currLNodeQ->choices[j]);
            if (isExist == true) {
                updateIsHit(&currLNodeQ->choices[j], true);
                totalNumOfHits++;
            } else {
                updateIsHit(&currLNodeQ->choices[j], false);
            }
        }
        updateLNodetotalOfHits(currLNodeQ, totalNumOfHits);
        currLNodeQ = currLNodeQ->next;
    }

}

void printHighestUser(ListUsers *listOfUsers) {
    User *highestUser;
    double max;
    if (listOfUsers == NULL) {
        return;
    }
    User *currUser = listOfUsers->head;
    highestUser = currUser;
    max = highestUser->avrageOfHits;

    while (currUser != NULL) {
        double currentUserTotalNumOfHits = currUser->avrageOfHits;
        if (max < currentUserTotalNumOfHits) {
            highestUser = currUser;
            max = currentUserTotalNumOfHits;
        }
        currUser = currUser->next;
    }
    printf("%s has the highest avergae of hits! with total of %.2f", highestUser->name, max);
}

void printUserListQ(ListUsers *listOfUsers) {
    int userCounter = 1;
    if (listOfUsers == NULL) {
        return;
    }
    User *currUser = listOfUsers->head;

    while (currUser != NULL) {
        printf("\n\n %s number %d, here are your queues by highest score to loweset: \n", currUser->name,
               userCounter);
        printListQ(currUser->listQ);
        currUser = currUser->next;
        userCounter++;
    }
}

void sortUsersListQs(ListUsers *listOfUsers) {
    if (listOfUsers == NULL) {
        return;
    }
    User *currUser = listOfUsers->head;

    while (currUser != NULL) {
        sortListQ(currUser->listQ);
        currUser = currUser->next;
    }
}


User *getUserWithHighestScore(ListUsers *ListOfUsers) {
    User *winner = NULL;
    User *curr;
    int max = 0;

    curr = ListOfUsers->head;

    while (curr != NULL) {
        if (curr->avrageOfHits > max) {
            winner = curr;
            max = curr->avrageOfHits;
            curr = curr->next;
        }
    }
    return winner;
}

int getUserTotalNumOfHits(User *user) {
    LNodeQ *curr;
    int totalHits = 0;

    curr = user->listQ->head;

    while (curr != NULL) {
        totalHits += curr->totalCountOfHits;
        curr->next;
    }
    return totalHits;
}

void updateUserAvarageOfHits(User *user) {
    int lNodeQCount = 0;
    double sum = 0;
    if (user == NULL) {
        return 0;
    }

    LNodeQ *currLnodeQ = user->listQ->head;
    while (currLnodeQ != NULL) {
        sum += currLnodeQ->totalCountOfHits;
        lNodeQCount++;
        currLnodeQ = currLnodeQ->next;
    }

    user->avrageOfHits = sum / lNodeQCount;
}

int getCountOfParticipants(ListUsers *lst) {
    int count = 0;
    User *curr;
    curr = lst->head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}

void freeUserList(ListUsers* users) {
    if (users == NULL) {
        return;
    }

    User* currentUser = users->head;
    while (currentUser != NULL) {
        freeListQ(currentUser->listQ);
        User* tmpUser = currentUser;
        currentUser = currentUser->next;
        free(tmpUser);
    }
    free(users);
}