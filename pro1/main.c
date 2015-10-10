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
    int flag;
    stack stack[10000];
}mouse;

int main(){
    int exit=0;
    char maze[2][MAX_SIZE][MAX_SIZE];
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
    while(1){
	if(A.floor == 1 && A.x == 99 && A.y == 99){
	    printf("A mouse have arrived goal.\n");
	    break;
	}
	if(B.floor == 0 && B.x == 1 && B.y == 1){
	    printf("B mouse have arrived goal.\n");
	    break;
	}
	if(A.floor == B.floor && A.x == B.x && A.y == B.y){
	    printf("A mouse and B mouse is together.\n");
	    break;
	}
	
	printf("A mouse is in (%d:%d:%d)\nB mouse is in (%d:%d:%d)\n",A.floor,A.x,A.y,B.floor,B.x,B.y);
    }
    return 0;

}
