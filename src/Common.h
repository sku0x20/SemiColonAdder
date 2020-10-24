#ifndef COMMON_H

#define COMMON_H

#include <stdbool.h>
#include <stdio.h>

#include "Constants.h"

// fun pointer can also be written as void callFun(char*)
// and can also be called as (*callFun)(word)

void lineToWords(char* itsLine, int startIndex, int endIndex, void (*callFun)(char*, int)) {
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
            callFun(word, i);
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
        callFun(word, i); // since space cannot be last word
        j = 0;
    }
}

// from should always contain '\0' at end
void copyString(char* from, char* to, bool includeTerminator) {
    int i;
    for (i = 0; from[i] != '\0'; i++) {
        to[i] = from[i];
    }
    if (includeTerminator) {
        to[i] = '\0';
    }
}

#endif