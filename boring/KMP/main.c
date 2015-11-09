#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[1000100];
char pat[10100];
int f[10100];
int lens,lenp;

void failure() {
    memset(f, 0, sizeof(f));

    int i = 0, j = 1;
    while (j < lenp) {
        if (pat[i] == pat[j]) {
            f[j] = i + 1;
            i++;
            j++;
        }else{
            if(i!=0){
                i = f[i-1];
            }else{
                f[j]=0;
                j++;
            }
        }
    }

}

int KMP() {
    int j=0;
    int i=0;
    int cnt=0;
    while(i<lens){
        //check match
        if(string[i] == pat[j]){
            i++;
            j++;
        //In start of pat not match then string ++.
        }else if(j==0) i++;
        //If not in start of pat, try j-1 prefix.
        else j = f[j-1];
        if(j==lenp){
            cnt++;
            //Here is j-1 because j already ++ in line 34~36.
            j = f[j-1];
        }
    }
    return cnt;
}


int main() {
    int n;
    scanf("%d\n",&n);

    while(n--) {
        memset(pat, '\0', sizeof(pat));
        fgets(pat,10100,stdin);
        lenp = strlen(pat);
        if(pat[lenp-1]=='\n') {
            pat[lenp-1] = '\0';
            lenp--;
        }
        memset(string, '\0', sizeof(string));
        fgets(string,1000100,stdin);
        lens = strlen(string);
        if(string[lens-1]=='\n') {
            string[lens-1] = '\0';
            lens--;
        }
        memset(f,0,sizeof(f));
        failure();
        printf("%d\n",KMP());
    }

    return 0;
}
