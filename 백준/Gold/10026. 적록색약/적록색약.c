#include <stdio.h>

int N;
char color[2][100][100]; // 0->Normal , 1->Have
int visit[100][100];
int count[2];            // 0->Normal , 1->Have
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init_visit() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            visit[i][j] = 0;
        }
    }
}

void make_Have() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(color[0][i][j] == 'G') 
                color[1][i][j] = 'R';
            else
                color[1][i][j] = color[0][i][j];
        }
    }
}

int is_valid(int x, int y) {
    if(x>=0 && x<N && y>=0 && y<N) return 1;
    return 0;
}

void dfs(int t, int y, int x) {
    visit[y][x] = 1;
    int base = color[t][y][x];
    
    int tx, ty;
    for(int a=0; a<4; a++) {
        tx = x + dx[a];
        ty = y + dy[a];
        if(is_valid(tx, ty) && !visit[ty][tx] && color[t][ty][tx]==base) {
            dfs(t, ty, tx);
        }
    }
}

void solve(int t) {
    init_visit();
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visit[i][j]) 
                count[t]++;
                dfs(t, i, j);
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf(" %c", &color[0][i][j]);
        }
    }
    make_Have();
    
    solve(0);
    solve(1);
    
    printf("%d %d\n", count[0], count[1]);
    
    return 0;
}