/*
Pure KMP problem
*/
#include <cstdio>
#include <cstring>

char p[10100], s[1000100];
int f[10100];

int plen, slen;

void fail_function()
{
    memset(f, 0, sizeof(f));

    int i = 0, j = 1;
    while (j < plen) {
        if (p[i] == p[j]) {
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

int KMP()
{
    int cnt = 0;

    int pidx = 0;
    for (int i = 0; i < slen; i++) {
        while (p[pidx] == s[i] && i < slen) {
            if (pidx == plen - 1) {
                cnt++;
                pidx = f[pidx];
                break;
            }
            pidx++;
            i++;
        }

        if (pidx != 0) {
            pidx = f[pidx - 1];
            i--;
        }
    }

    return cnt;
}

int main()
{
    char input[10];
    int ncase;
    fgets(input, 10, stdin);
    sscanf(input, "%d", &ncase);

    while (ncase--) {
        fgets(p, 10100, stdin);
        p[(plen = strlen(p) - 1)] = '\0';
        fgets(s, 1000100, stdin);
        s[(slen = strlen(s) - 1)] = '\0';

        fail_function();
        printf("%d\n", KMP());
    }

    return 0;
}
