#include <stdio.h>
#include <stdlib.h>

int main(){
    int temp;
    int a[10] = {18,25,25,23,26,23,22,23,22,24};
    for(int i = 0; i<10; i++){
	for(int j = 0; j<10-i; j++){
	    if(a[j]-a[j+1]<0){
		temp = a[j];
		a[j] = a[j+1];
		a[j+1] = temp;
	    }
	}
    }
    for(int i=0; i<10; i++)
	printf("%d%c",a[i],i==9 ? '\n' : ' ');
    return 0;
}
