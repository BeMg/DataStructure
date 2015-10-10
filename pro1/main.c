#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 105


typedef struct {
    int x;
    int y;
    int f;
    int dir;
}stack;

typedef struct {
    int f;
    int x;
    int y;
}mouse;

mouse RAT_A,RAT_B;
stack stack_a[MAX_SIZE*MAX_SIZE+10],stack_b[MAX_SIZE*MAX_SIZE+10];

void RAT_init(){
    RAT_A.f = 0;
    RAT_A.x = 1;
    RAT_A.y = 1;    
    RAT_B.f = 1;
    RAT_B.x = 99;
    RAT_B.y = 99;

}

int CHECK_A_IN_goal(){
    if(RAT_A.f == 1 && RAT_A.x == 99 && RAT_A.y == 99)
	return 1;
    return 0;
}

int CHECK_B_IN_goal(){
    if(RAT_B.f == 0 && RAT_B.x == 1 && RAT_B.y == 1)
	return 1;
    return 0;
}

int CHECK_A_AND_B_IS_TOGETHER(){
    if(RAT_A.f == RAT_B.f && RAT_A.x == RAT_B.x && RAT_A.y == RAT_B.y)
	return 1;
    return 0;
}



char maze[2][MAX_SIZE][MAX_SIZE];
void GET_INPUT(){
    int temp;
    //input
    for(int i=0; i<2; i++){
	scanf("%d\n",&temp);
	for(int j=0; j<=100; j++){
	    fgets(maze[i][j],105,stdin);
	    int len = strlen(maze[i][j]);
	    if(maze[i][j][len-1]=='\n'){
		maze[i][j][len-1] = '\0';
		len--;
	    }
	}
    }
}

void WHERE_IS_RAT(){
    printf("A mouse is in (%d:%d:%d)\nB mouse is in (%d:%d:%d)\n",A.floor,A.x,A.y,B.floor,B.x,B.y);
}

int main(){
    GET_INPUT();
    RAT_init();
    while(1){
	if(CHECK_A_IN_goal()){
	    printf("A mouse have arrived goal.\n");
	    break;
	}
	if(CHECK_B_IN_goal()){
	    printf("B mouse have arrived goal.\n");
	    break;
	}
	if(CHECK_A_AND_B_IS_TOGETHER()){
	    printf("A mouse and B mouse is together.\n");
	    break;
	}
	
    WHERE_IS_RAT();
    }
    return 0;

}
