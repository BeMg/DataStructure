#include <stdio.h>
#include <string.h>

int f[10000],f2[100000];
char a[10000];
int len;

void fail_function()
{
    memset(f, 0, sizeof(f));
    int i = 0, j = 1;
    while (j < len) {
        if (a[i] == a[j]) {
            f[j] = i + 1;
            i++;
            j++;
        } else {
            if (i != 0) {
                i = f[i - 1];
            } else {
                f[j] = 0;
                j++;
            }
        }
    }
}

void failure() {
    memset(f2, 0, sizeof(f));

    int i = 0, j = 1;
    while (j < len) {
        if (a[i] == a[j]) {
            f2[j] = i + 1;
            i++;
            j++;
        }else{
            j++;
            i=0;
        }
    }

}

int main(){
    fgets(a,10000,stdin);
    len = strlen(a);
    if(a[len-1]=='\n'){
        a[len-1] = '\0';
        len--;
    }
    failure();
    fail_function();
    for(int i=0; i<len; i++){
        printf("%d%c",f[i],i==len-1 ? '\n' : ' ');
    }
    for(int i=0; i<len; i++){
        printf("%d%c",f2[i],i==len-1 ? '\n' : ' ');
    }
}
