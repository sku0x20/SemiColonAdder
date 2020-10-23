#ifndef MY_PARSER_H

#define MY_PARSER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 256

FILE* readFile;
FILE* writeFile;

char itsLine[LINE_LENGTH];

int startIndex;

int endIndex;

void trimWhiteSpace() {
    int len = strlen(itsLine);

    for (endIndex = len - 2; (itsLine[endIndex] == ' ') || (itsLine[endIndex] == '\n'); endIndex--)
        ;

    for (startIndex = 0; itsLine[startIndex] == ' '; startIndex++)
        ;
}

bool readLine() {
    if (fgets(itsLine, LINE_LENGTH, readFile) == NULL) {
        return false;
    }

    trimWhiteSpace();
    return true;
}

void startParsing(char const* const readFilename, char const* const writeFileName) {
    readFile = fopen(readFilename, "r");
    writeFile = fopen(writeFileName, "w");

    while (readLine()) {
        printf("startIndex = %d, endIndex = %d \n", startIndex, endIndex);
    }

    fclose(readFile);
    fclose(writeFile);
}

#endif