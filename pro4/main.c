#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CheckForItem[6];
int CheckForSorted[6];
int CheckForSelect;
int CheckForForm;
int CheckForOrder;
int CheckForBy;
int First;
int Second;

char a[100000];
char path[10000];
char col[6][10] = {"Id","FirstName","LastName","Gender","Age","PhoneNum"};

typedef struct {
    int Id;
    char FirstName[15];
    char LastName[15];
    char Gender;
    int Age;
    char PhoneNum[18];
} Date;

Date data[10000];
int data_cnt=0;

int item_cmp(int a, int b, int n) {
    switch (n) {
    case 0:
        return data[a].Id - data[b].Id;
        break;
    case 1:
        return strcmp(data[a].FirstName,data[b].FirstName);
               break;
    case 2:
        return strcmp(data[a].LastName,data[b].LastName);
               break;
    case 3:
        return data[a].Gender - data[b].Gender;
               break;
    case 4:
        return data[a].Age - data[b].Age;
               break;
    case 5:
        return strcmp(data[a].PhoneNum,data[b].PhoneNum);
               break;
    }
    return 0;
}

int cmp(int a, int b) {
    int temp;
    if(Second!=-1 && item_cmp(a,b,First)) {
        temp = item_cmp(a,b,Second);
        if(CheckForSorted[Second]<0)
            return -temp;
        else
            return temp;
    }
    else {
        temp = item_cmp(a,b,First);
        if(CheckForSorted[First]<0)
            return -temp;
        else
            return temp;
    }
}

int stable_sort(int a, int b) {
    if(item_cmp(a,b,First) == 0 && item_cmp(a,b,Second) == 0)
        return data[a].Id - data[b].Id;
    return 0;
}


void swap(void *a,void *b,size_t size) {
    void* temp = malloc(sizeof(data));
    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
    free(temp);
}

int partition(void *a,int len,int pivot_idx,size_t size) {
    int i;
    swap(a+pivot_idx*size,a+(len-1)*size,size);
    int storeindex = 0;
    for(i=0; i<len-1; i++) {
        printf("A: %d B: %d\n",i,len-1);
        if(cmp(i,len-1)<0) {
        swap(a+i*size,a+storeindex*size,size);
            storeindex++;
        }
    }
    swap(a+(len-1)*size,a+storeindex*size,size);
    return storeindex;
}

void quick_sort(void *a,int len,size_t size) {
    srand(time(NULL));
    if(len==0 || len == 1) return;
    int pivot = rand()%len;
    int small_len = partition(a,len,pivot,size);
    quick_sort(a,small_len,size);
    quick_sort(a+(small_len+1)*size,len-small_len-1,size);
}

void bubble_sort(void *a,int len,size_t size) {
    for(int i=0; i<len; i++) {
        for(int j=0; j<i-1; j++) {
            if(cmp(i,j)<0)
                swap(a+i*size,a+j*size,size);
        }
    }
}

/*inital all variable*/

void variable_init() {
    memset(CheckForItem,0,sizeof(CheckForItem));
    memset(CheckForSorted,0,sizeof(CheckForSorted));
    First = -1;
    Second = -1;
    CheckForSelect = 0;
    CheckForForm = 0;
    CheckForOrder = 0;
    CheckForBy = 0;
    data_cnt = 0;
}

/*transfer string to easy-use number*/

int CheckWhatGet(char* temp) {
    if(strcmp(temp,"Id")==0)
        return 0;
    if(strcmp(temp,"FirstName")==0)
        return 1;
    if(strcmp(temp,"LastName")==0)
        return 2;
    if(strcmp(temp,"Gender")==0)
        return 3;
    if(strcmp(temp,"Age")==0)
        return 4;
    if(strcmp(temp,"PhoneNum")==0)
        return 5;
    if(strcmp(temp,"SELECT")==0 || strcmp(temp,"select")==0)
        return 6;
    if(strcmp(temp,"FROM")==0 || strcmp(temp,"from")==0)
        return 7;
    if(strcmp(temp,"ORDER")==0 || strcmp(temp,"order")==0)
        return 8;
    if((strcmp(temp,"BY")==0 || strcmp(temp,"by")==0))
        return 9;
    if(strcmp(temp,"*")==0)
        return 10;
    return -1;
}

/*SortOption is different from other, so let it independent.*/

int CheckForSortOption(char* temp) {
    if(strcmp(temp,"-1")==0)
        return 1;
    if(strcmp(temp,"-2")==0)
        return 2;
    if(strcmp(temp,"DESC")==0)
        return 3;
    if(strcmp(temp,"ASC")==0)
        return 4;
    return -1;
}

/*
We should getline and strtok by space to get string.
Use mode to control the flow.
mode 0 start
mode 1 select
mode 2 from
mode 3 Sort Option
*/

void Get_input() {
    char* temp = strtok(a," ,");
    int mode = 0;
    int item = 0;
    while(temp!=NULL) {
        int input = CheckWhatGet(temp);
        if(input == 6) {
            mode = 1;
            CheckForSelect = 1;
        }
        else if(input == 7 && mode == 1) {
            mode = 2;
            CheckForForm = 1;
        }
        else if(input == 8 && mode == 2) {
            mode = 3;
            CheckForOrder = 1;
        }
        else if(input == 9 && mode == 3 ) {
            CheckForBy = 1;
        }
        else if(mode == 1) {
            if(input == 10) {
                for(int i=0; i<6; i++) {
                    CheckForItem[i] = 1;
                }
            }
            else
                CheckForItem[input] = 1;
        }
        else if(mode == 2) {
            strcpy(path,temp);
        }
        else if(mode == 3) {
            if(input == -1) {
                input = CheckForSortOption(temp);
                if(input == 2)
                    CheckForSorted[item]*=2;
                else if(input == 3)
                    CheckForSorted[item] = -CheckForSorted[item];
            }
            else {
                item = input;
                if(First==-1)
                    First = item;
                else
                    Second = item;
                CheckForSorted[item] = 1;
            }
        }
        temp = strtok(NULL," ,");
    }

}

/*
fopen to read file, in file is not exist, print error.
transfering "" and , to space is easy to find the data.
*/

int Get_file() {
    FILE* pfile = fopen(path,"r");
    if(pfile==NULL)
        return 1;
    char inp[10000];
    while(fgets(inp,10000,pfile)!=NULL) {
        int len = strlen(inp);
        if(inp[len-1]=='\n') {
            inp[len-1] = '\0';
            len--;
        }
        for(int i=0; i<len; i++) {
            if(inp[i]=='\"' || inp[i]==',')
                inp[i] = ' ';
        }
        sscanf(inp,"%d %s %s %c %d %s",&data[data_cnt].Id,data[data_cnt].FirstName,
               data[data_cnt].LastName,&data[data_cnt].Gender,&data[data_cnt].Age,data[data_cnt].PhoneNum);
        memset(inp,'\0',sizeof(inp));
        data_cnt++;
    }
    fclose(pfile);
    return 0;
}

/*
Two accept format
Select = from = 1, order = by = 0
Select = from = order = by = 1
*/

int Syntax_ERROR() {
    if(CheckForSelect && CheckForForm) {
        if(CheckForOrder+CheckForBy == 1)
            return 1;
        return 0;
    }
    return 1;
}

void print() {
    int flag = 1;
    for(int i=0; i<6; i++) {
        if(CheckForItem[i]) {
            if(flag) {
                printf("%s",col[i]);
                flag = 0;
            }
            else {
                printf("\t%s",col[i]);
            }
        }
    }
    printf("\n");
    flag = 1;
    for(int i=0; i<data_cnt; i++) {
        if(CheckForItem[0]) {
            if(flag==1)
                flag = 0;
            else
                printf("\t");
            printf("%d",data[i].Id);
        }
        if(CheckForItem[1]) {
            if(flag==1)
                flag = 0;
            else
                printf("\t");
            printf("%s",data[i].FirstName);
        }
        if(CheckForItem[2]) {
            if(flag==1)
                flag = 0;
            else
                printf("\t");
            printf("%s",data[i].LastName);
        }
        if(CheckForItem[3]) {
            if(flag==1)
                flag = 0;
            else
                printf("\t");
            printf("%c",data[i].Gender);
        }
        if(CheckForItem[4]) {
            if(flag==1)
                flag = 0;
            else
                printf("\t");
            printf("%d",data[i].Age);
        }
        if(CheckForItem[5]) {
            if(flag==1)
                flag = 0;
            else
                printf("\t");
            printf("%s",data[i].PhoneNum);
        }
        printf("\n");
        flag = 1;
    }
}

void Double_sort() {
    printf("IN\n");
    if(abs(CheckForSorted[First])==1)
        quick_sort(data,data_cnt,sizeof(data));
    /*
    else if(abs(CheckForSorted[First])==2)
        bubble_sort(data,data_cnt,sizeof(data));
    if(abs(CheckForSorted[Second])==1)
        quick_sort(data,data_cnt,sizeof(data));
    else if(abs(CheckForSorted[Second])==2)
        bubble_sort(data,data_cnt,sizeof(data));
    */
    printf("OUT\n");
}



int main() {
    while(fgets(a,100000,stdin)) {
        variable_init();
        int len = strlen(a);
        if(a[len-1]=='\n') {
            a[len-1] = '\0';
            len--;
        }
        if(strcmp(a,"quit")==0)break;
        Get_input();
        /*
        printf("Select: ");
        for(int i=0; i<6; i++)
            printf("%d%c",CheckForItem[i],i==5 ? '\n' : ' ');
        printf("Sort: ");
        for(int i=0; i<6; i++)
            printf("%d%c",CheckForSorted[i],i==5 ? '\n' : ' ');
        puts(path);
        */
        if(Syntax_ERROR()) {
            printf("You have an error in your SQL syntax.\n");
            continue;
        }
        if(Get_file()) {
            printf("This file does not exist!\n");
            continue;
        }
        /*
        for(int i=0; i<data_cnt; i++){
            printf("%d\t%s\t%s\t%c\t%d\t%s\n",data[i].Id,data[i].FirstName,
                data[i].LastName,data[i].Gender,data[i].Age,data[i].PhoneNum);
        }
        */
        print();
    }
    return 0;
}
