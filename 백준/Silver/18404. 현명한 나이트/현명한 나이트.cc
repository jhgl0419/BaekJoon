#include <iostream>
#include <queue>

#define INT_MAX 0x7fffffff
// x또는 y한칸 움직이는데 최대 3 => 최대 3*500*500 = 750'000회

using namespace std;

int N, M;
int kx, ky;

int chess[501][501];

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

bool can_go(int x, int y) {
    return 0 < x && x <= N && 0 < y && y <= N;
}

void bfs(int x, int y) {
    int tx, ty;
    queue <pair<int, pair<int, int>>> q;
    q.push({ 0, {x, y} });
    chess[x][y] = 0;

    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int cnt = t.first + 1;
        tx = t.second.first; ty = t.second.second;

        int nx, ny;
        for (int i = 0; i < 8; i++) {
            nx = tx + dx[i];
            ny = ty + dy[i];

            if (can_go(nx, ny) && chess[nx][ny] > cnt) {
                chess[nx][ny] = cnt;
                q.push({ cnt, {nx,ny} });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;

    cin >> kx >> ky;

    fill(&chess[1][1], &chess[500][501], INT_MAX);

    bfs(kx, ky);
    
    int ex, ey;
    for (int i = 0; i < M; i++) {
        cin >> ex >> ey;
        cout << chess[ex][ey] << " ";
    }
    cout << "\n";
    
    return 0;
}
