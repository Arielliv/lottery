#pragma once

#include "file.h"

typedef unsigned char BYTE;

// Gets a binary file and uncompress its data, creates and returns a pointer to a newly created
// array of intigers, re-stored from the received file
int *uncompressDataOfSingleQueue(FILE *fpResults);

// This fuction gets choices from a queue and stores it
// in a compressed way in a given binary file
BYTE *compressDataOfSingleQueue(FILE *fpResults, Choice *choices);