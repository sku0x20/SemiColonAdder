#ifndef MY_PARSER_H

#define MY_PARSER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constants.h"
#include "MultiLineCommentFormatter.h"

FILE* readFile;
FILE* writeFile;

char itsLine[LINE_LENGTH];

int startIndex;

int endIndex;

char* formattedLine;

void trimWhiteSpace() {
    int len = strlen(itsLine);  // exculding null character

    for (endIndex = len - 1; (endIndex >= 0) && ((itsLine[endIndex] == ' ') || (itsLine[endIndex] == '\n')); endIndex--)
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

    multiLineFormatter(itsLine, startIndex, endIndex, formattedLine);
}

void startParsing(char const* const readFilename, char const* const writeFileName) {
    readFile = fopen(readFilename, "r");
    writeFile = fopen(writeFileName, "w");

    formattedLine = (char*)malloc(LINE_LENGTH * sizeof(char));

    while (readLine()) {
        // printf("startIndex = %d, endIndex = %d \n", startIndex, endIndex);
        // check if its empty line if so just write it there is no need to call any formatters
        if (endIndex == -1) {
            fputs("\n", writeFile);
        } else {
            callFormatters();
            for (int i = 0; i < startIndex; i++) {
                fputc(' ', writeFile);
            }
            fputs(formattedLine, writeFile);
            fputs("\n", writeFile);
        }
    }

    fclose(readFile);
    fclose(writeFile);

    free(formattedLine);
}

#endif