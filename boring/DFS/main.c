#include <stdio.h>
#include <string.h>

typedef struct {
    int x,y;
} Stack;

int route[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};

int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        int maze[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&maze[i][j]);
        Stack s[n*n+2];
        int step = 0;
        Stack m;
        m.x = 1;
        m.y = 1;

        while(1) {
            maze[m.x][m.y] = 2;
            int flag = 0;
            if(m.x==n-2 && m.y==n-2)break;
            for(int i=0; i<4; i++) {
                m.x+=route[i][0];
                m.y+=route[i][1];
                if(maze[m.x][m.y]==0){
                    flag = 1;
                    break;
                }
                m.x-=route[i][0];
                m.y-=route[i][1];
            }
            if(flag)
                s[++step] = m;
            else{
                maze[m.x][m.y] = 3;
                m = s[--step];
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(maze[i][j]==2)
                    printf("#");
                else if(maze[i][j]==3)
                    printf("*");
                else
                    printf("%d",maze[i][j]);
                printf("%c",j==n-1 ? '\n' : ' ');
                }
        }
    }
    return 0;
}
