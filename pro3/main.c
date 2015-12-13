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
int ans_owe;
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


int dfs(int curr, int route, int carry, int owe){

    if(curr == u){
        if(route == shortest){
            if(abs(ans)+abs(ans_owe) > abs(carry)+abs(owe)){
                ans = carry;
                ans_owe = owe;
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
    int need;
    for(int i=1; i<v; i++){
        if(G[curr][i]!=0 && !used[i]){
            need = (bike[i]-volumn/2);
            if(need>=0)
                dfs(i,route+G[curr][i],carry,owe+need);
            else{
                if(owe>abs(need)){
                    dfs(i,route+G[curr][i],carry,owe-abs(need));
                }else
                    dfs(i,route+G[curr][i],carry+abs(need)-owe,0);
            }
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
    bike[0] = 0;
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
    /*
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            printf("%d%c",G[i][j],j==v-1 ? '\n' : ' ');
        }
    }
    */
    floyd_Warshall();
    shortest = dist[0][u];
    dfs(0,0,0,0);
    //printf("ans:%d %d\n",ans_owe,ans);

    printf("%d ",ans);
    for(int i=0; i<=ans_cnt; i++){
        printf("%d>",ans_route[i]);
    }
    printf("%d %d\n",u,ans_owe);

    return 0;
}
