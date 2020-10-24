#ifndef COMMON_H

#define COMMON_H

#include <stdio.h>

#include "Constants.h"

void lineToWords(char* itsLine, int startIndex, int endIndex) {
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
        char* cursor = word;
        while (*cursor) {
            printf("%02x ", *cursor);
            ++cursor;
        }
        printf("\n");
        j = 0;
    }
}

#endif