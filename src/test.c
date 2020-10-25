#include <stdbool.h>
#include <stdio.h>

#include "MyParser.h"

bool checkArgs(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    if (!checkArgs(argc, argv)) {
        printf("Error:- Args are Incorrect \n");
        return EXIT_FAILURE;
    }

    char const* const readFileName = argv[1];
    char const* const writeFileName = argv[2];

    startParsing(readFileName, writeFileName);

    return EXIT_SUCCESS;
}

bool checkArgs(int argc, char* argv[]) {
    if (argc < 3) {
        return false;
    }
    return true;
}