#pragma once

#include "file.h"
typedef unsigned char BYTE;

int* uncompressDataOfSingleQueue(FILE* fpResults);

BYTE* compressDataOfSingleQueue(FILE* fpResults, Choice* choices);