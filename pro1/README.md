# MAZE

## INTRODUCTION

This is a story about two rats in the maze which has two floor.

## FILE

main.c

Just like its name.
    
mazes.txt

It is data of maze.

In the maze,

    "X" = wall
    "." = the way rat can go
    "o" = the stair between two floors

result.txt

It is answer generate from program.

### HOW PROGRAM TO WORK

First, program will read the mazes.txt from file itself. It will have two floors maze. In the begin, the rat A is in (0,1,1) and the rat B is in (1,99,99).
    
Second, let they go until three situation "A in (1,99,99)" "B in (0,1,1)" "A and B in same position". The program must stop, because maze must have way. Don't worry. 

### HOW I CREATE AND USE STACK

I use array to simulate stack. It is easy and work. Just use array to store position of rat and let flag add.

### WHAT BUG I MEET AND HOW TO DEFEAT

I had three fatal bug happen. They are all hard to debug and waste my time. 
    
First bug is logic error. I don't let stair to way which rat can go. So they always can't go up and down. So sad :(. Second bug is bad define to up and down. In my word, it is mean if rat in  the stair just go down or up. it can't fly in the sky.Third bug is output error, easy to debug. Ya!
    
## Compile

You should use gcc -std=c99 to compile.
	
    gcc -std=c99 -o a.out main.c
    
Or you can Makefile in file.
	
    make
    
Two way all generate the file named "a.out".

## RUN

Run a.out and enjoy.




