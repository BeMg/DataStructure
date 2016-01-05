#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int p[1000+3];

typedef struct {
    int x,y,cost;
}edge;


int find(int x){
    return x==p[x] ? x : (p[x] = find(p[x]));
}

void init(){
    for(int i=0; i<1004; i++){
	p[i] = i;
    }
}

void Union(int x, int y){
    p[find(x)] = find(y);
}


int cmp(const void*a,const void*b){
    edge* ea = (edge*)a;
    edge* eb = (edge*)b;
    return ea->cost - eb->cost;
}


int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)){
	if(n==0 && m==0)break;
	edge a[m];
	init();
	int flag = 0;
	for(int i=0; i<m; i++){
	    scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].cost);
	}
	int ans[m];
	int cnt = 0;
	qsort(a,m,sizeof(edge),cmp);
	for(int i=0; i<m; i++){
	    if(find(a[i].x)==find(a[i].y)){
		ans[cnt++] = a[i].cost;
	    }
	    else{
		Union(a[i].x,a[i].y);
	    }
	}
	if(cnt==0)
	    printf("forest\n");
	else{
	    for(int i=0; i<cnt; i++){
		printf("%d%c",ans[i],i==cnt-1 ? '\n' : ' ');
	    }
	}
    
    }
    return 0;
}
