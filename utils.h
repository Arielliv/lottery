#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

// Prints an error if fails to open the received file
void checkFile(FILE *fp);

void checkMemoryAllocation(void *ptr);