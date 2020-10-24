#ifndef MULTI_LINE_COMMENT_FORMATTER_H

#define MULTI_LINE_COMMENT_FORMATTER_H

#include <stdbool.h>

#include "Common.h"

void format(char* word, int index);

char* formattedLine;

int endInd;

bool isComment;

bool wordIsCode = false;

int i;

void multiLineFormatter(char* itsLine, int startIndex, int endIndex, char* fL) {
    i = 0;
    endInd = endIndex;
    lineToWords(itsLine, startIndex, endIndex, format);
    formattedLine[i] = '\0';
    // printf("%s \n", fL);
}

void format(char* word, int index) {
    int wordLen = strlen(word);

    if (word[0] == ' ') {
        copyString(word, formattedLine + i, false);
        i = i + wordLen;
        return;
    }

    // we have to somehow extract this code check so it applies
    if ((word[0] == '/') && (word[1] == '*')) {
        isComment = true;
        if ((index > wordLen) && (wordIsCode)) {
            formattedLine[i] = ';';
            i = i + 1;
        }
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

    copyString(word, formattedLine + i, false);
    i = i + wordLen;

    if ((!isComment) && (wordIsCode) && (index > endInd)) {
        formattedLine[i] = ';';
        i = i + 1;
    }
}

#endif

// int a = 565646/*dasd*/ we won't cover this type of comments there should be gap

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