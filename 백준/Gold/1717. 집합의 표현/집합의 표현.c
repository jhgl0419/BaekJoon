#include <stdio.h>

int getParent(int *parent, int i) {
    if(parent[i] == i) return i;
    return parent[i] = getParent(parent, parent[i]);
}

void unionParent(int *parent, int a, int b) {
    int pa = getParent(parent, a);
    int pb = getParent(parent, b);
    
    if(pa < pb) parent[pb] = pa;
    else parent[pa] = pb;
}

int isSame(int *parent, int a, int b) {
    int pa = getParent(parent, a);
    int pb = getParent(parent, b);
    
    if(pa == pb) return 1;
    else return 0;
}

int main() {
    int n,m; scanf("%d %d", &n, &m);
    int *rel = malloc(sizeof(int) * (n+1));
    for(int i=1; i<=n; i++) rel[i] = i;
    
    int cmd;
    int a,b;
    while(m--) {
        scanf("%d", &cmd);
        switch(cmd) {
            case 0:
                scanf("%d %d", &a, &b);
                unionParent(rel, a, b);
                break;
            case 1:
                scanf("%d %d", &a, &b);
                printf("%s\n", isSame(rel, a, b) ? "YES" : "NO");
                break;
            default:
                break;
        }
    }
    
    return 0;
}
