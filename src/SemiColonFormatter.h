#ifndef SEMI_COLON_FORMATTER_H

#define SEMI_COLON_FORMATTER_H

#include <stdbool.h>
#include <string.h>

#include "Common.h"

void format(char* word, int index);

char* formattedLine;

int startInd;
int endInd;

bool isComment;

bool wordIsCode = false;

bool skipLine = false;

int i;

void semiColonFormatter(char* itsLine, int startIndex, int endIndex, char* fL) {
    i = 0;
    startInd = startIndex;
    endInd = endIndex;
    skipLine = false;

    if ((itsLine[startIndex] == '#') || ((itsLine[startIndex] == '/') && itsLine[startIndex + 1] == '/')) {
        skipLine = true;
    }

    lineToWords(itsLine, startIndex, endIndex, format);
    formattedLine[i] = '\0';
    // printf("%s \n", fL);
}

void format(char* word, int index) {
    int wordLen = strlen(word);

    if ((word[0] == ' ') || skipLine) {
        copyString(word, formattedLine + i, false);
        i = i + wordLen;
        return;
    }

    //single line conditions
    if ((word[0] == '/') && (word[1] == '/')) {
        if (wordIsCode) {
            formattedLine[i] = ';';
            i = i + 1;
        }
        skipLine = true;
        copyString(word, formattedLine + i, false);
        i = i + wordLen;
        return;
    }

    // multiline conditions
    if ((word[0] == '/') && (word[1] == '*')) {
        if ((index > wordLen) && (wordIsCode)) {
            formattedLine[i] = ';';
            i = i + 1;
        }
        isComment = true;
        wordIsCode = false;

    } else if ((word[0] == '*') && (word[1] == '/')) {
        isComment = false;
        wordIsCode = false;
    } else {
        wordIsCode = true;
    }
    if ((word[wordLen - 2] == '*') && (word[wordLen - 1] == '/')) {
        isComment = false;
        wordIsCode = false;
    }

    // { & } case
    if((word[wordLen - 1] == '{') || (word[wordLen - 1] == '}')){
        wordIsCode = false;
    }

    copyString(word, formattedLine + i, false);
    i = i + wordLen;

    if ((!isComment) && (wordIsCode) && (index > endInd)) {
        formattedLine[i] = ';';
        i = i + 1;
    }
}

#endif

// int a = 565646/*dasd*/ we won't cover this type of comments there should be gap between code and comment

/*
void format(char* word) {
    if (word[0] == ' ') {
        char* cursor = word;
        while (*cursor) {
            printf("%02x ", *cursor);
            ++cursor;
        }
        printf("\n");
    } else {
        printf("%s \n", word);
    }
}
*/