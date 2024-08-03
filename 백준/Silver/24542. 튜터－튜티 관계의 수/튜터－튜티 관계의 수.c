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

int main() {
    int N, M; scanf("%d %d", &N, &M);
    int rel[N+1];
    for(int i=0; i<=N; i++) {
        rel[i] = i;
    }
    
    int a,b;
    for(int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        unionParent(rel, a, b);
    }
    int count[N+1];
    for(int i=0; i<=N; i++) count[i] = 0;
    for(int i=1; i<=N; i++) {
        count[getParent(rel, i)]++;
    }
    
    long long result = 1;
    for(int i=1; i<=N; i++) {
        if(count[i] != 0) {
            result = (result * count[i]) % 1000000007;
        }
    }
    
    printf("%lld\n", result);
    
    return 0;
}