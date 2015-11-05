# DS Homework 2

## Introduction

We have two tasks.
1. implement a binary search tree using links.
2. follow the description and make **treasure hunter**.

## Compile and run

Use Makefile

```
all:main.c

        gcc -std=c99 -o a.out main.c

clean:

		-rm *.o *.c.orig *.h.gch *.h.orig
```

Just `make`

`a.out` is the executable file.

## Start menu
Program will print out following words.

```
(I)mplement
(T)reasure hunter
(E)xit
```
Enter `I` or `T` or `E`, to continue.

## Implementation

If you enter `I` in the menu, you will see following words.

```
(S)earch
(I)nsert
(D)elete
(P)rintorder
(E)xit
```

It is easy to understand.

## Treasure hunter

If you enter `T` in the menu.

You shall enter the data name for the program to load.

If the file doesn't exist, the error messages will be printed and you will return to the main menu.

Otherwise, simply enter key and treasure positions.

The result will be shown on the screen.
