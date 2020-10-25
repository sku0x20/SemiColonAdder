# SemiColonAdder
Appends Semicolon to C files.


### Usage:- 
```
./semiColonAdder readFileName writeFileName
```

### Example:-
```C
// cFile.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char const *const fileName = argv[1]
    FILE* file = fopen(fileName, "r") 
    char line[256]

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line)
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    printf("\n")

    fclose(file)

    return 0
}
```
Will get Converted to,
```C
// cFile.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char const *const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line);
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    printf("\n");

    fclose(file);

    return 0;
}
```
### Tests
3 test cases are tested which are included in tests folder. <br />
```
./semiColonAdder ../tests/simpleSemicolonTest simpleSemicolonTest
./semiColonAdder ../tests/differentEnds.txt differentEnds.c
./semiColonAdder ../tests/cFile.c cFile.c
```
