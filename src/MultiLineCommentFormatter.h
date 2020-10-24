#ifndef MULTI_LINE_COMMENT_FORMATTER_H

#define MULTI_LINE_COMMENT_FORMATTER_H

#include "Common.h"

void format(char* word);

char* formattedLine;

void multiLineFormatter(char* itsLine, int startIndex, int endIndex, char* fL) {
    lineToWords(itsLine, startIndex, endIndex, format);
}

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

#endif