#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyParser.h"

/*
void writeLine();
int getNewLineIndex();
void constructAndWriteNewLine(int newLineIndex);
void addNewLine();
void addSemiColon(int newLineIndex);
*/
bool checkArgs(int argc, char* argv[]);

// char readLine[LINE_LENGTH];

FILE* writeFile;

int main(int argc, char* argv[]) {
    if (!checkArgs(argc, argv)) {
        printf("Error:- Args are Incorrect \n");
        return EXIT_FAILURE;
    }

    char const* const readFileName = argv[1];
    char const* const writeFileName = argv[2];

    startParsing(readFileName, writeFileName);

    /*
    char const* const fileName = argv[1];
    char const* const writeFileName = argv[2];

    FILE* file = fopen(fileName, "r");
    writeFile = fopen(writeFileName, "w");

    while (fgets(readLine, sizeof(readLine), file)) {
        writeLine();
    }

    fclose(file);
    fclose(writeFile);

    */

    return EXIT_SUCCESS;
}

bool checkArgs(int argc, char* argv[]) {
    if (argc < 3) {
        return false;
    }
    return true;
}

/*
void writeLine() {
    int newLineIndex = getNewLineIndex();

    if (newLineIndex < 0) {  // continuos line case
        fputs(readLine, writeFile);
    }

    if (newLineIndex > 0) {
        char lastChar = readLine[newLineIndex - 1];
        constructAndWriteNewLine(newLineIndex);
    }

    addNewLine();
}

void constructAndWriteNewLine(int newLineIndex) {
    char lineWithoutNewLine[newLineIndex + 1];

    snprintf(lineWithoutNewLine, newLineIndex + 1, "%s", readLine);

    fputs(lineWithoutNewLine, writeFile);

    addSemiColon(newLineIndex);
}

void addSemiColon(int newLineIndex) {
    char firstChar = readLine[0];
    char secondChar = readLine[1];

    char lastChar = '\0';
    char secondLastChar = '\0';

    if (newLineIndex > 1) {
        lastChar = readLine[newLineIndex - 1];
        secondLastChar = readLine[newLineIndex - 2];
    } else if (newLineIndex == 1) {
        lastChar = readLine[newLineIndex - 1];
    }

    if (firstChar == '#')
        ;
    else if (lastChar == '{')
        ;
    else if (lastChar == '}')
        ;
    else if (firstChar == '/' && secondChar == '/')
        ;
    else if (secondLastChar == '*' && lastChar == '/')
        ;
    else {
        fputc(';', writeFile);
    }
}

int getNewLineIndex() {
    int stringLength = strlen(readLine);

    if (stringLength == LINE_LENGTH) {  // buffer full but no new line
        return -1;
    }
    if (readLine[stringLength - 1] != '\n') {
        //EOF case
        return stringLength;
    }

    int index = stringLength - 1;
    return index;
}

void addNewLine() {
    fputc('\n', writeFile);
}

*/