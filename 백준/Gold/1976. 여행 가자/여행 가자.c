#include <stdio.h>

int getParent(int *parent, int i) {
    if(parent[i] == i) return i;
    return parent[i] = getParent(parent, parent[i]);
}

void unionParent(int *root, int i, int j) {
    int pi = getParent(root, i);
    int pj = getParent(root, j);
    
    if(pi < pj) root[pj] = pi;
    else root[pi] = pj;
}

int main() {
    int N; scanf("%d", &N);
    int M; scanf("%d", &M);
    
    int root[N];
    for(int i=0; i<N; i++) {
        root[i] = i;
    }
    int input;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &input);
            if(input == 1) {
                unionParent(root, i, j);
            }
        }
    }
    
    int order[M];
    int tmp;
    for(int i=0; i<M; i++) {
        scanf("%d", &tmp);
        order[i] = tmp-1;
    }
    for(int i=0; i<M-1; i++) {
        if(getParent(root, order[i]) != getParent(root, order[i+1])) {
            puts("NO");
            goto END;
        }
    }
    puts("YES");
END:
    return 0;
}