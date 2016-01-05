#include <stdio.h>
#include <stdlib.h>

int main(){
    freopen("data.txt","w",stdout);
    for(int i=0; i<100; i++){
	printf("%d\n",rand()%100);
    }
    return 0;
}
