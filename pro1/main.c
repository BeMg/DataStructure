#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


typedef struct {
    int x;
    int y;
    int f;
    int dir;
} stack;

typedef struct {
    int f;
    int x;
    int y;
} mouse;

mouse RAT_A,RAT_B;
stack stack_a[MAX_SIZE*MAX_SIZE+10],stack_b[MAX_SIZE*MAX_SIZE+10];

int flag_A = 1;
int flag_B = 1;

void RAT_init() {
    RAT_A.f = 0;
    RAT_A.x = 1;
    RAT_A.y = 1;
    RAT_B.f = 1;
    RAT_B.x = MAX_SIZE-1;
    RAT_B.y = MAX_SIZE-1;

}

int CHECK_A_IN_goal() {
    if(RAT_A.f == 1 && RAT_A.x == MAX_SIZE-1 && RAT_A.y == MAX_SIZE-1)
        return 1;
    return 0;
}

int CHECK_B_IN_goal() {
    if(RAT_B.f == 0 && RAT_B.x == 1 && RAT_B.y == 1)
        return 1;
    return 0;
}

int CHECK_A_AND_B_IS_TOGETHER() {
    if(RAT_A.f == RAT_B.f && RAT_A.x == RAT_B.x && RAT_A.y == RAT_B.y)
        return 1;
    return 0;
}

char maze[2][MAX_SIZE+10][MAX_SIZE+10];
int  A_table[2][MAX_SIZE][MAX_SIZE];
int  B_table[2][MAX_SIZE][MAX_SIZE];



void GET_INPUT() {
    int temp;
    //input
    for(int i=0; i<2; i++) {
        scanf("%d\n",&temp);
        for(int j=0; j<=MAX_SIZE; j++) {
            fgets(maze[i][j],MAX_SIZE+5,stdin);
            int len = strlen(maze[i][j]);
            if(maze[i][j][len-1]=='\n') {
                maze[i][j][len-1] = '\0';
                len--;
            }
        }
    }
}



void ARAT_RUN() {
    stack_a[flag_A].f = RAT_A.f;
    stack_a[flag_A].x = RAT_A.x;
    stack_a[flag_A].y = RAT_A.y;
    //printf("stack:%d %d %d %d %d\n",flag_A,stack_a[flag_A].f,stack_a[flag_A].x,stack_a[flag_A].y,stack_a[flag_A].dir);
    stack_a[flag_A].dir = 0;
    if(!A_table[RAT_A.f][RAT_A.x][RAT_A.y])
        A_table[RAT_A.f][RAT_A.x][RAT_A.y] = 1;
    else
        A_table[RAT_A.f][RAT_A.x][RAT_A.y]++;

    if(maze[RAT_A.f][RAT_A.x][RAT_A.y]=='o' && stack_a[flag_A].dir <= 0 && !RAT_A.f) {
        RAT_A.f = 1;
        stack_a[flag_A++].dir = 0;
    } else if(!A_table[RAT_A.f][RAT_A.x][RAT_A.y+1] && (maze[RAT_A.f][RAT_A.x][RAT_A.y+1]=='o' || maze[RAT_A.f][RAT_A.x][RAT_A.y+1]=='.')) {
        RAT_A.y++;
        stack_a[flag_A++].dir = 1;
    } else if(!A_table[RAT_A.f][RAT_A.x+1][RAT_A.y] && (maze[RAT_A.f][RAT_A.x+1][RAT_A.y]=='o' || maze[RAT_A.f][RAT_A.x+1][RAT_A.y]=='.')) {
        RAT_A.x++;
        stack_a[flag_A++].dir = 2;
    } else if(!A_table[RAT_A.f][RAT_A.x-1][RAT_A.y] && (maze[RAT_A.f][RAT_A.x-1][RAT_A.y]=='o' || maze[RAT_A.f][RAT_A.x-1][RAT_A.y]=='.')) {
        RAT_A.x--;
        stack_a[flag_A++].dir = 3;
    } else if(!A_table[RAT_A.f][RAT_A.x][RAT_A.y-1] && (maze[RAT_A.f][RAT_A.x][RAT_A.y-1]=='o' || maze[RAT_A.f][RAT_A.x][RAT_A.y-1]=='.')) {
        RAT_A.y--;
        stack_a[flag_A++].dir = 4;
    } else {
        flag_A--;
        RAT_A.f = stack_a[flag_A].f;
        RAT_A.x = stack_a[flag_A].x;
        RAT_A.y = stack_a[flag_A].y;
    }
    if(maze[RAT_A.f][RAT_A.x][RAT_A.y]=='o' && !RAT_A.f) {
        RAT_A.f = 1;
    }
}

void BRAT_RUN() {
    stack_b[flag_B].f = RAT_B.f;
    stack_b[flag_B].x = RAT_B.x;
    stack_b[flag_B].y = RAT_B.y;
    //printf("stack:%d %d %d %d %d\n",flag_A,stack_a[flag_A].f,stack_a[flag_A].x,stack_a[flag_A].y,stack_a[flag_A].dir);
    if(!B_table[RAT_B.f][RAT_B.x][RAT_B.y])
        B_table[RAT_B.f][RAT_B.x][RAT_B.y] = 1;
    else
        B_table[RAT_B.f][RAT_B.x][RAT_B.y]++;

    stack_b[flag_B].dir = 0;

    if(maze[RAT_B.f][RAT_B.x][RAT_B.y]=='o' && stack_b[flag_B].dir <= 0 && RAT_B.f) {
        RAT_B.f = 0;
        stack_b[flag_B++].dir = 0;
    } else if(!B_table[RAT_B.f][RAT_B.x][RAT_B.y-1] && (maze[RAT_B.f][RAT_B.x][RAT_B.y-1]=='o' || maze[RAT_B.f][RAT_B.x][RAT_B.y-1]=='.')) {
        RAT_B.y--;
        stack_b[flag_B++].dir = 1;
    } else if(!B_table[RAT_B.f][RAT_B.x-1][RAT_B.y] && (maze[RAT_B.f][RAT_B.x-1][RAT_B.y]=='o' || maze[RAT_B.f][RAT_B.x-1][RAT_B.y]=='.')) {
        RAT_B.x--;
        stack_b[flag_B++].dir = 2;
    } else if(!B_table[RAT_B.f][RAT_B.x+1][RAT_B.y] && (maze[RAT_B.f][RAT_B.x+1][RAT_B.y]=='o' || maze[RAT_B.f][RAT_B.x+1][RAT_B.y]=='.')) {
        RAT_B.x++;
        stack_b[flag_B++].dir = 3;
    } else if(!B_table[RAT_B.f][RAT_B.x][RAT_B.y+1] && (maze[RAT_B.f][RAT_B.x][RAT_B.y+1]=='o' || maze[RAT_B.f][RAT_B.x][RAT_B.y+1]=='.')) {
        RAT_B.y++;
        stack_b[flag_B++].dir = 4;
    } else {
        flag_B--;
        RAT_B.f = stack_b[flag_B].f;
        RAT_B.x = stack_b[flag_B].x;
        RAT_B.y = stack_b[flag_B].y;
    }
    if(maze[RAT_B.f][RAT_B.x][RAT_B.y]=='o' && RAT_B.f) {
        RAT_B.f = 0;
    }
}

void WHERE_IS_RAT() {
    printf("ratA(%d,%d,%d)\n",RAT_A.f,RAT_A.x,RAT_A.y);
    printf("ratB(%d,%d,%d)\n",RAT_B.f,RAT_B.x,RAT_B.y);
}

void PUTS_INPUT() {
    for(int i=0; i<2; i++) {
        for(int j=0; j<=MAX_SIZE; j++)
            puts(maze[i][j]);
    }
}

int main() {
    GET_INPUT();
    RAT_init();
    PUTS_INPUT();
    while(1) {
        ARAT_RUN();
        BRAT_RUN();
        if(CHECK_A_IN_goal()) {
            printf("rats didn't encounter each other in this maze\n");
            break;
        }
        if(CHECK_B_IN_goal()) {
            printf("rats didn't encounter each other in this maze\n");
            break;
        }
        if(CHECK_A_AND_B_IS_TOGETHER()) {
            printf("rats encounter each other in this maze\n");
            break;
        }
        WHERE_IS_RAT();
    }
    /*for(int k = 0; k<2; k++) {
        for(int i=0; i<=MAX_SIZE; i++) {
            for(int j=0; j<=MAX_SIZE; j++) {
                printf("%d%c",A_table[k][i][j],j==MAX_SIZE ? '\n' : ' ');
            }
        }
    }*/

    return 0;

}
