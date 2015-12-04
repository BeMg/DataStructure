#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int volumn,v,u,m;
int bike[MAX];
int dist[MAX][MAX];
int used[MAX]={0};
long long int shortest;
int G[MAX][MAX]={0};
int cnt = -1;
int ans_cnt = 0;
int ans=1e9;
int ans_route[MAX];
int temp[MAX];


void floyd_Warshall(){
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dist[i][j] > dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int pow_function(int n){
    int num=1;
    for(int i=0; i<n; i++)
        num*=10;
    return num;
}

int dfs(int curr, int route, int carry){
    if(route > shortest)
        return 0;
    if(curr == u){
        if(route == shortest){
            if(abs(ans) > abs(carry)){
                ans = carry;
                //printf("cnt: %d\n",cnt);
                //puts(temp);
                memset(ans_route,'\0',sizeof(ans_route));
                ans_cnt = cnt;
                for(int i=0; i<=cnt; i++)
                    ans_route[i] = temp[i];
            }
        }
        return 0;
    }
    used[curr] = 1;
    cnt++;
    temp[cnt] = curr;
    for(int i=1; i<v; i++){
        if(G[curr][i]!=0 && !used[i]){
            dfs(i,route+G[curr][i],carry+volumn/2-bike[i]);
        }
    }
    used[curr] = 0;
    temp[cnt] = 0;
    cnt--;
    return 0;
}



int main(){
    scanf("%d %d %d %d",&volumn,&v,&u,&m);
    v++;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = 1e9;
        }
    }
    for(int i=1; i<v; i++)
        scanf("%d",&bike[i]);
    int from,to,far;
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&from,&to,&far);
        /*
        if(G[to][from] || G[from][to]){
            while(1){
                printf("error\n");
            }
        }
        */
        G[to][from] = far;
        G[from][to] = far;
        dist[to][from] = far;
        dist[from][to] = far;
    }
    floyd_Warshall();
    shortest = dist[0][u];
    dfs(0,0,0);
    if(ans>=0){
        printf("%d ",ans);
        for(int i=0; i<=ans_cnt; i++){
            printf("%d>",ans_route[i]);
        }
        printf("%d 0\n",u);
    }else if(ans<0){
        printf("0 ");
        for(int i=0; i<=ans_cnt; i++){
            printf("%d>",ans_route[i]);
        }
        printf("%d %d\n",u,-ans);
    }
    return 0;
}
