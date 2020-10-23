#ifndef MY_PARSER_H

#define MY_PARSER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 256  // including null character
#define WORD_LENGTH 256

FILE* readFile;
FILE* writeFile;

char itsLine[LINE_LENGTH];

int startIndex;

int endIndex;

void trimWhiteSpace() {
    int len = strlen(itsLine);  // exculding null character

    for (endIndex = len - 1; (itsLine[endIndex] == ' ') || (itsLine[endIndex] == '\n'); endIndex--)
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

bool isLastLine() {
    if (itsLine[(strlen(itsLine) - 1)] != '\n') {
        return true;
    }
    return false;
}

void callFormatters() {
    bool lastLine = isLastLine();

    static char word[WORD_LENGTH];

    int i = startIndex;
    int j = 0;
    while (i <= endIndex) {  // Reformat This Remove code dupication
        // words
        while (itsLine[i] != ' ') {
            word[j] = itsLine[i];
            j++;
            i++;
            if (i > endIndex) {
                break;
            }
        }
        if (j != 0) {
            word[j] = '\0';
            // call different Formatters Here
            printf("%s \n", word);
            j = 0;
            continue;
        }
        // spaces
        while (itsLine[i] == ' ') {
            word[j] = ' ';
            j++;
            i++;
            if (i > endIndex) {  // this condition should never be true
                break;
            }
        }
        word[j] = '\0';
        // call different Formatters Here
        char *cursor = word;
        while (*cursor) {
            printf("%02x ", *cursor);
            ++cursor;
        }
        printf("\n");
        j = 0;
    }
}

void startParsing(char const* const readFilename, char const* const writeFileName) {
    readFile = fopen(readFilename, "r");
    writeFile = fopen(writeFileName, "w");

    while (readLine()) {
        // printf("startIndex = %d, endIndex = %d \n", startIndex, endIndex);
        // check if its empty line( from startIndex and EndIndex ) if so just write it there is no need to call any formatters
        callFormatters();
    }

    fclose(readFile);
    fclose(writeFile);
}

#endif