#include <stdio.h>

int min(int a,int b){
    return a>b ? b : a;  
}

void BottomUpMerge(int A[], iLeft, iRight, iEnd, B[]){
    int i = iLeft, j = iRight;
    for(int k= iLeft; k< iEnd; k++){
	if()
    }
}

int Merge_sort(int A[],int B[],int n){
    for(int w = 1; w<n; w = 2*w){
	for(int i=0; i<n; i= i+2*w){
	    Merge(A,i,min(i+w,n),min(i+2*w,n),B);
	}
	CopyArray(B,A,n);
    }
}

int main(){
    int a[100];
    for(int i=0; i<100; i++)
	scanf("%d",&a[i]);
    int b[100];
    Merge_sort(a,b,100);   
    
}
