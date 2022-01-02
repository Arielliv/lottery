// Shelly Srour - 316384254, Ariel Livshits - 315363366
#define _CRT_SECURE_NO_WARNINGS

#include "compress.h"

int *uncompressDataOfSingleQueue(FILE *fpResults) {
    int i, choice1 = 0, choice2 = 0;
    BYTE mask1 = 0xF0;      // 11110000
    BYTE mask2 = 0x0F;      // 00001111
    int res[6];

    for (i = 0; i < 6; i = i + 2) // unCompress 3 bytes
    {
        BYTE *data = (BYTE *) malloc(sizeof(BYTE) * 1);
        fread(data, sizeof(BYTE), 1, fpResults);

        choice1 = (*data & mask1) >> 4;
        choice2 = (*data & mask2);

        res[i] = choice1;
        res[i + 1] = choice2;
    }
    return res;
}

BYTE *compressDataOfSingleQueue(FILE *fpResults, Choice *choices) {
    int i, choice1 = 0, choice2 = 0, byteCounter = 0;
    BYTE tmp = 0x00;
    BYTE *res;

    res = (BYTE *) malloc(sizeof(BYTE) * 3);

    for (i = 0; i < 6; i = i + 2) // Create 3 bytes
    {
        choice1 = choices[i].data;
        choice2 = choices[i + 1].data;

        tmp = (BYTE) choice1 << 4;
        tmp = (tmp | (BYTE) choice2);

        res[byteCounter] = tmp;
        byteCounter++;
    }
    return res;
}