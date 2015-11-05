# DS Homework 2

## Introduction

We have two tasks.
1. implement a binary search tree use link.
2. follow the describe make **treasure hunter**.

## Compile and run

Use Makefile

```
all:main.c

        gcc -std=c99 -o a.out main.c

clean:

		-rm *.o *.c.orig *.h.gch *.h.orig
```

Just `make`

`a.out` is execution file.

## Start menu
Program will print follow word.

```
(I)mplement
(T)reasure hunter
(E)xit
```
Enter `I` or `T` or `E`, to continue.

## Implementation

If you enter `I` in meue, you will see follow word.

```
(S)earch
(I)nsert
(D)elete
(P)rintorder
(E)xit
```

It is easy to understand.

## Treasure hunter

If you enter `T` in meue.

you shell enter the data name to let program read.

If doesn't have file, print error message and return.

And enter key and treasure position.

Result will show on the screen.
