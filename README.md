# SemiColonAdder
Adds Semicolon to C files


### Usage:- 
```
./test readFileName writeFileName
```

### Example:-
After
```
./test differentEnds.txt tempFile.c
```
We get tempFile with Semicolons.

### Exception:-
1. The C code should be formated as Google Format Specifiers. <br />
2. Comment should not be in same line as Code. <br />
eg:-
```
int a = 6 // comment OR
int b = 7 /* comment */
```
