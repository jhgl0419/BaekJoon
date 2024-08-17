#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int v;
    struct _Node *next;
} Node;

typedef struct _Tree {
    int root;
    Node* parent[50];
} Tree;

Tree *t;
int N;
int x;
int count;
int child_count[50];

void dfs(int s) {
    if(s == x) return;
    
    Node *m = t->parent[s];
    if(m==NULL || (child_count[s]==1 && m->v==x)) count++;
    while(m) {
        dfs(m->v);
        m = m->next;
    }
}

void init_tree() {
    t = malloc(sizeof(Tree));
    for(int i=0; i<N; i++) {
        t->parent[i] = NULL;
        child_count[i] = 0;
    }
}

void insert(int p, int c) {
    if(p==-1) {
        t->root = c;
        return;
    }
    
    Node *new = malloc(sizeof(Node));
    new->v = c;
    new->next = t->parent[p];
    t->parent[p] = new;
    child_count[p]++;
}

int main() {
    scanf("%d", &N);
    init_tree();
    int tmp;
    for(int i=0; i<N; i++) {
        scanf("%d", &tmp);
        insert(tmp, i);
    }
    
    scanf("%d", &x);

    dfs(t->root);
    printf("%d\n", count);
    
    return 0;
}