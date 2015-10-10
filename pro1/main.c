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
    int floor;
    int x;
    int y;
    int flag;
    stack a[10000];
}mouse;

int main(){
    char maze[2][MAX_SIZE][MAX_SIZE];
    memset(maze,'\0',sizeof(maze));
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
    //test for input is work.
    /*for(int i=0; i<2; i++){
      printf("%d\n",i+1);
      for(int j=0; j<=100; j++)
      puts(maze[i][j]);
      }*/
    mouse A;
    A.floor = 0;
    A.x = 1;
    A.y = 1;
    A.flag = 0;
    mouse B;
    B.floor = 1;
    B.x = 99;
    B.y = 99;
    B.flag = 0;
    
    while(1){
	if(A.floor == 1 && A.x == 99 && A.y == 99){
	    printf("A mouse have arrived goal.\n");
	    break;
	}
	if(B.floor == 0 && B.x = 1 && B.y == 1){
	    printf("B mouse have arrived goal.\n");
	    break;
	}
	A.stack[A.flag].x = A.x;
	A.stack[A.flag].y = A.y;
	A.stack[A.flag].f = A.floor;
	if(!A.floor && maze[A.floor][A.x][A.y] == 'o'){
	    A.floor = 1;
	    A.stack[flag].dir = 0;
	    A.flag++;
	}else if(A.stack[A.flag].dir==0 &&  maze[A.floor][A.x+1][A.y] == '.'){
	    A.x++;
	    A.stack[flag].dir = 1;
	    A.flag++;
	}else if(A.stack[A.flag].dir==1 && maze[A.floor][A.x][A.y-1] == '.'){
	    A.y--;
	    A.stack[A.flag].dir = 2;
	    A.flag++;
	}else if(A.stack[A.flag].dir==2 && maze[A.floor][A.x][A.y+1] == '.'){
	    A.y++;
	    A.stack[A.flag].dir = 3;
	    A.flag++;
	}else if(A.stack[A.flag].dir == 3 && maze[A.floor][A.x-1][A.y] == '.'){
	    A.x--;
	    A.stack[A.flag].dir = 4;
	    A.flag++;
	}else{
	    A.flag--;
	    A.x = A.stack[A.flag].x;
	    A.y = A.stack[A.flag].y;
	    A.floor = A.stack[A.flag].f;
	}
	B.stack[B.flag].x = B.x;
	B.stack[B.flag].y = B.y;
	B.stack[B.flag].f = B.floor;
	B.stack
	if(B.floor && maze[B.floor][B.x][B.y] == 'o'){
	    B.floor = 0;
	    B.stack[B.flag].dir = 0;
	    B.flag++;
	}else if(B.stack[B.flag].dir==0 &&  maze[B.floor][B.x-1][B.y] == '.'){
	    B.x--;
	    B.stack[B.flag].dir = 1;
	    B.flag++;
	}else if(B.stack[B.flag].dir==1 && maze[B.floor][B.x][B.y+1] == '.'){
	    B.y++;
	    B.stack[B.flag].dir = 2;
	    B.flag++;
	}else if(B.stack[B.flag].dir==2 && maze[B.floor][B.x][B.y-1] == '.'){
	    B.y--;
	    B.stack[flag].dir = 3;
	    B.flag++;
	}else if(B.stack[B.flag].dir == 3 && maze[B.floor][B.x+1][B.y] == '.'){
	    B.x++;
	    B.stack[B.flag].dir = 4;
	    B.flag++;
	}else{
	    B.flag--;
	    B.x = B.stack[B.flag].x;
	    B.y = B.stack[B.flag].y;
	    B.floor = B.stack[B.flag].f;
	}

    }
    return 0;

}
