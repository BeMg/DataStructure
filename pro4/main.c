#include <string.h>
#include <stdio.h>

int CheckForItem[6];
int CheckForSorted[6];
int CheckForSelect;
int CheckForForm;
int CheckForOrder;


char a[100000];
char path[10000];

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

void variable_init() {
    memset(CheckForItem,0,sizeof(CheckForItem));
    memset(CheckForSorted,0,sizeof(CheckForSorted));
    CheckForSelect = 0;
    CheckForForm = 0;
    CheckForOrder = 0;
}

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
        else if(input == 7) {
            mode = 2;
            CheckForForm = 1;
        }
        else if(input == 8) {
            mode = 3;
        }
        else if(input == 9 && mode == 3) {
            CheckForOrder = 1;
        }
        else if(mode == 1) {
            if(input == 10)
                memset(CheckForItem,1,sizeof(CheckForItem));
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
                CheckForSorted[item] = 1;
            }
        }
        temp = strtok(NULL," ,");
    }

}

void Get_file() {
    FILE* pfile = fopen(path,"r");
    char inp[10000];
    while(fgets(inp,10000,pfile)!=NULL){
        int len = strlen(inp);
        if(inp[len-1]=='\n'){
            inp[len-1] = '\0';
            len--;
        }
        for(int i=0; i<len; i++){
            if(inp[i]=='\"' || inp[i]==',')
                inp[i] = ' ';
        }
        sscanf(inp,"%d %s %s %c %d %s",&data[data_cnt].Id,data[data_cnt].FirstName,
            data[data_cnt].LastName,&data[data_cnt].Gender,&data[data_cnt].Age,data[data_cnt].PhoneNum);
        memset(inp,'\0',sizeof(inp));
        data_cnt++;
    }
    fclose(pfile);
}

int main() {
    while(fgets(a,100000,stdin)) {
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
        Get_file();
        /*
        for(int i=0; i<data_cnt; i++){
            printf("%d\t%s\t%s\t%c\t%d\t%s\n",data[i].Id,data[i].FirstName,
                data[i].LastName,data[i].Gender,data[i].Age,data[i].PhoneNum);
        }
        */
    }
    return 0;
}
