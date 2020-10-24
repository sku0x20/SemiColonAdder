#ifndef MULTI_LINE_COMMENT_FORMATTER_H

#define MULTI_LINE_COMMENT_FORMATTER_H

#include "Common.h"

char* formattedLine;

void multiLineFormatter(char* itsLine, int startIndex, int endIndex, char* fL){
    lineToWords(itsLine, startIndex, endIndex);
}

#endif