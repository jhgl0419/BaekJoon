#include <stdio.h>

typedef struct tomato {
    int x,y,z;
} T;

int box[100][100][100];
T q[1000000];
int first=0, last=-1;
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

void bfs(int M, int N, int H) {
    int x, y, z;
    int px, py, pz;
    while(first <= last) {
        x = q[first].x, y = q[first].y, z = q[first++].z;
        for(int i=0; i<6; i++) {
            px = x+dx[i], py = y+dy[i], pz = z+dz[i];
            if(px>=0&&px<M && py>=0&&py<N && pz>=0&&pz<H
                    && box[pz][py][px] == 0) {
                
                box[pz][py][px] = box[z][y][x] + 1;
                q[++last].x=px,q[last].y=py,q[last].z=pz;
            }
        }
    }
}

int main() {
    int M, N, H; scanf("%d %d %d", &M, &N, &H);

    for(int z=0; z<H; z++) {
        for(int y=0; y<N; y++) {
            for(int x=0; x<M; x++) {
                scanf("%d", &box[z][y][x]);
                if(box[z][y][x] == 1) {
                    q[++last].x=x, q[last].y=y, q[last].z=z;
                }
            }
        }
    }
    bfs(M,N,H);
    int days = 0;
    for(int z=0; z<H; z++) {
        for(int y=0; y<N; y++) {
            for(int x=0; x<M; x++) {
                if(box[z][y][x] == 0) {
                    days = -1;
                    goto END;
                }
                else if(days < box[z][y][x]-1) {
                    days = box[z][y][x]-1;
                }
            }
        }
    }
END:
    printf("%d\n", days);

    return 0;
}