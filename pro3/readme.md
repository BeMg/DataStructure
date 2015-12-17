# DS HWC Graph

Student ID: 403410061
Name: Chen, Pi-You

#HOW TO COMPLIE

```
gcc -std=c99 -o a.out main.c
```

## INTRO

Ubike is a bike-rent service, we have to make a shortest path to remain the balance of bike in each station.

## HOW TO WORK

Use Floya-Warshall to find the shortest path from start to goal. Then DFS all possible path to balance bike number, choice the least cost one. Output it.
