#include <stdio.h>
#include <stdlib.h>

typedef struct _Box {
    int weight;
    int onBoard;
} Box;

int compare(const void *a, const void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    
    return *pb - *pa;
}

int compareA(const void *a, const void *b) {
    Box *pa = (Box *)a;
    Box *pb = (Box *)b;
    
    return pb->weight - pa->weight;
}

int main() {
    int N; scanf("%d", &N);    // 1<= N <= 50
    int W[N];
    for(int i=0; i<N; i++) {
        scanf("%d", &W[i]);    // W[i] <= 1,000,000
    }
    
    int M; scanf("%d", &M);
    Box boxes[M];
    for(int i=0; i<M; i++) {
        scanf("%d", &boxes[i].weight);   // pW[i] <= 1,000,000
        boxes[i].onBoard = 0;
    }
    qsort(W, sizeof(W)/sizeof(int), sizeof(int), compare);
    qsort(boxes, sizeof(boxes)/sizeof(Box), sizeof(Box), compareA);

    int minutes = 0;
    if(W[0] < boxes[0].weight) {
        minutes = -1;
        goto End;
    }
    int i_box;
    int j;
    int is_Empty;
    while(1) {
        i_box = 0;
        is_Empty = 1;
        for(int i=0; i<N; i++) {
            for(j=i_box; j<M; j++) {
                if(boxes[j].onBoard != 0) continue;
                if(W[i] >= boxes[j].weight) {
                    boxes[j].onBoard = 1;
                    is_Empty = 0;
                    i_box = j+1;
                    break;
                }
            }
            if(j == M) break;
        }
        if(is_Empty == 1) break;
        minutes++;
    }
End:    
    printf("%d\n", minutes);
    
    return 0;
}