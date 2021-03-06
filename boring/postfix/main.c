#include <stdio.h>
#include <string.h>

int isp[] = {0,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};
//lparen, rparen, plus, minus, times, divide, mod, eos, operand
int top = 0;
int stack[500];


int trans(char *symbol) {
    switch (symbol[0]) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 3;
    case '*':
        return 4;
    case '/':
        return 5;
    case '%':
        return 6;
    case ' ':
        return 7;
    default :
        return 8;
    }
}
char a = '%';
void print(int token) {
    switch (token) {
    case 2:
        printf("+");
        break;
    case 3:
        printf("-");
        break;
    case 4:
        printf("*");
        break;
    case 5:
        printf("/");
        break;
    case 6:
        printf("%c",a);
        break;
    }
}

int pop() {
    top--;
    return stack[top+1];
}

void push(int temp) {
    stack[++top] = temp;
}


int main() {
    int n;
    int token;
    scanf("%d\n",&n);
    char symbol[5];
    fgets(symbol,5,stdin);
    int flag = 1;
    while(n--) {
        if(flag)
            flag = 0;
        else
            printf("\n");
        top = 0;
        stack[top] = 7;
        while(fgets(symbol,5,stdin)!=NULL && symbol[0]!='\n') {
            //printf("Stack: ");
            //for(int i=0; i<=top; i++)
            //    printf("%d%c",stack[i],i==top ? '\n' : ' ');
            int len = strlen(symbol);
            symbol[len-1] = '\0';
            token = trans(symbol);
            //printf("Token: %c\n",token);
            //printf("Token : %d\n",token);
            if(token == 8) {
                printf("%c",symbol[0]);
            } else if(token == 1) {
                while(stack[top]!= 0) {
                    print(pop());
                }
                pop();
            }
            else {
                //printf("isp: %d icp: %d\n",isp[stack[top]],icp[token]);
                while(isp[stack[top]]>=icp[token]) {
                    print(pop());
                }
                push(token);
            }
        }
        while((token = pop())!= 7)
            print(token);
        printf("\n");
    }
    return 0;
}
