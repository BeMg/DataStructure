#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int b[10] = {9,8,7,6,5,4,3,2,1,0};

int cmp(const void*a,const void*b){
    return *(int*)a - *(int*)b;
}

int cmp1(int i, int j){
    return b[i] - b[j];
}

void swap(void *a,void *b,size_t size){
    void* temp = malloc(size);
    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
    free(temp);
}

int partition(void *a,int len,int pivot_idx,size_t size,int (*cmp)(const void*a,const void*b)){
        int i;
        swap(a+pivot_idx*size,a+(len-1)*size,size);
        int storeindex = 0;
        for(i=0; i<len-1; i++){
            if(cmp(a+i*size,a+(len-1)*size)<0){
                swap(a+i*size,a+storeindex*size,size);
                storeindex++;
            }
        }
        swap(a+(len-1)*size,a+storeindex*size,size);
        return storeindex;
}

void quick_sort(void *a,int len,size_t size,int (*cmp)(const void*a,const void*b)){
    if(len==0 || len == 1) return;
    int pivot = rand()%len;
    int small_len = partition(a,len,pivot,size,cmp);
    quick_sort(a,small_len,size,cmp);
    quick_sort(a+(small_len+1)*size,len-small_len-1,size,cmp);
}


int main(){
    quick_sort(b,10,sizeof(int),cmp);
    for(int i=0; i<10; i++)
        printf("%d%c",b[i],i==9 ? '\n' : ' ');
    return 0;
}
