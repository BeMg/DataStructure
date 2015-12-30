# DS HW4

## INTRO

Create a SQL-like database for the data that looks like phone book.


## COMPILATION

```shell
gcc -std=c99 -o a.out main.c
```

## SORT ALGORITHM

Using two algorithms

1. Bubble Sort (default)

2. Quick Sort

## HOW IT WORKS

1. Read commands in a line, and checks the syntax.

>Use `strtok` to get all key words. There are three modes in this section.

>* mode 1 Select
>* mode 2 from
>* mode 3 order by(option)

>It must have mode 1 & 2.

>In mode 1

>>Create CheckForItem array to record what >item we need to show in the last.

> In mode 2

> >Follow the From must be the path of file.

> In mode 3

>> Separately record which sort-type and DESC or AES in CheckForSorted.

2.

Call sort function to sort it. Need use stable sort to maintain result is answer.

3.

Print all need to print. All thing back with \t.
