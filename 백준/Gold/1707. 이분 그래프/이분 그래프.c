#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct _node{
    int val;
    struct _node *next;
} Node;

typedef struct _graph {
    int root;
    Node *rel[20001];
} Graph;

int V, E, flag=1;
Graph *g;
int check[20001];

void init_Graph() {
    g->root = 1;
    for(int i=1; i<=V; i++) {
        g->rel[i] = NULL;
    }
}

void insert_edge(int v1, int v2) {
    Node *new = malloc(sizeof(Node));
    new->val = v2;
    new->next = g->rel[v1];
    g->rel[v1] = new;
}

void dfs(int s, int pre) {
    check[s] = pre * -1;
    Node *tmp = g->rel[s];
    while(tmp) {
        if(!check[tmp->val]) {
            dfs(tmp->val, check[s]);
        }
        else if(check[s] == check[tmp->val]) {
            flag = 0;
            return;
        }
        tmp = tmp->next;
    }
}

int main() {
    int K;
    scanf("%d", &K);
    
    int v1, v2;
    g = malloc(sizeof(Graph));
    while(K--) {
        scanf("%d %d", &V, &E);
        init_Graph();
        memset(check, 0, sizeof(check));
        for(int i=0; i<E; i++) {
            scanf("%d %d", &v1, &v2);
            insert_edge(v1, v2);
            insert_edge(v2, v1);
        }
        flag = 1;
        for(int i=1; i<=V; i++) {
            if(!check[i])
                dfs(i, 1);
        }
        printf("%s\n", flag?"YES":"NO");
    }
    
    return 0;
}