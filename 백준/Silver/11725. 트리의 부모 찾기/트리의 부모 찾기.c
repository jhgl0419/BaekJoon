#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int N;
int parent[MAX+1];
int visit[MAX+1];

typedef struct _Node {
    int v;
    struct _Node *next;
} Node;

typedef struct _Tree {
    int n;
    Node *link[MAX+1];
} Tree;

void insert_edge(Tree *t, int s, int e) {
    Node *new = malloc(sizeof(Node));
    new->v = e;
    new->next = t->link[s];
    t->link[s] = new;
}

int queue[MAX];
int first = 0;
int last = -1;

void push(int val) {
    queue[++last] = val;
}

int pop() {
    return queue[first++];
}

void bfs(Tree *t, int start) {
    push(start);
    visit[start] = 1;

    int val;
    while(first <= last) {
        val = pop();
        for(Node *i=t->link[val]; i; i=i->next) {
            if(!visit[i->v]) {
                parent[i->v] = val;
                push(i->v);
                visit[i->v] = 1;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    Tree *t = malloc(sizeof(Tree));
    t->n = N;
    for(int i=1; i<=N; i++) {
        t->link[i] = NULL;
    }

    int t1, t2;
    for(int i=1; i<N; i++) {
        scanf("%d %d", &t1, &t2);

        insert_edge(t, t1, t2);
        insert_edge(t, t2, t1);
    }

    bfs(t, 1);

    for(int i=2; i<=N; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;    
}