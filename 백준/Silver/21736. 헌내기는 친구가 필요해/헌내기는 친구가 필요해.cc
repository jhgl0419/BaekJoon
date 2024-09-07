#include <iostream>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M, c = 0;
char campus[600][600];			// 360,000 array도 가능.
bool visit[600][600];

bool is_valid(int x, int y) {
	if (x >= 0 && x <= M && y >= 0 && y <= N)
		return true;

	return false;
}

void dfs(int x, int y) {
	visit[y][x] = true;
	int tx, ty;
	for (int i = 0; i < 4; i++) {
		tx = dx[i] + x;
		ty = dy[i] + y;
		if (is_valid(tx, ty) && !visit[ty][tx]) {
			switch (campus[ty][tx]) {
			case 'P':
				c++;
			case 'O':
				dfs(tx, ty);
				break;
			default:
				break;
			}
			
		}
	}

}

int main() {
	//freopen("input.txt", "r", stdin);

	int curX, curY;
	char tmp;

	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &campus[i][j]);
			if(campus[i][j] == 'I') {
				curX = j; curY = i;
			}
		}
	}

	dfs(curX, curY);
	if (c != 0)
		printf("%d\n", c);
	else
		puts("TT");
	return 0;
}