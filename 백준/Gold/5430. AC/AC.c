#include <stdio.h>

int array[100000], first, last, flag = 1; // 1: 정방향, -1: 반대 방향

void R() {
    flag *= -1;
    int tmp = last;
    last = first;
    first = tmp;
}

int D() {
    if((flag == 1 && first > last) || (flag == -1 && first < last)) {
        return -1;
    }
    int ret = array[first];
    first += flag;
    return ret;
}

int main() {
    int T; scanf("%d", &T);
    char tmp;
    char cmd[100001]; 
    while(T--) {
        scanf("%s", cmd);
        int n; scanf("%d", &n);
        int num = 0;
        flag = 1, first = 0, last = -1;
        scanf(" %c", &tmp); // '['
        while(1) {
            if(n!=0) {
                scanf("%d", &num);
                array[++last] = num;
            }
            if(getchar() == ']') break; // ']'&&','
        }
        int i=0, error=0;
        while(cmd[i]!='\0') {
            if(cmd[i]=='R') {
                R();
            }
            else if(cmd[i]=='D') {
                error = D();
                if(error==-1) {
                    puts("error");
                    break;
                }
            }
            i++;
        }
        if(error==-1) continue;
        int f=0;
        printf("[");
        while(1) {
            if((flag == 1 && first > last) || (flag == -1 && first < last)) break;
            if(f) {
                printf(",");
            }
            printf("%d", array[first]);
            f++;
            first += flag;
        }
        printf("]\n");
    }

    return 0;
}