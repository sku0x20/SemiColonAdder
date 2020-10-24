#ifndef COMMON_H

#define COMMON_H

#include <stdio.h>

#include "Constants.h"

// fun pointer can also be written as void callFun(char*)
// and can also be called as (*callFun)(word)

void lineToWords(char* itsLine, int startIndex, int endIndex, void (*callFun)(char*)) {
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
            callFun(word);
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
        callFun(word);
        j = 0;
    }
}

#endif