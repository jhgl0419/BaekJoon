#include <iostream>
#define INF 100

using namespace std;

int N, M;

int rel[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	fill(&rel[0][0], &rel[100][101], INF);

	int u, v;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		rel[u][v] = 1;
		rel[v][u] = 1;
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = i + 1; j <= N; ++j) {
				if(rel[i][k] == INF || rel[k][j] == INF) continue;
                v = rel[i][k] + rel[k][j];
				if (v < rel[i][j]) {
					rel[i][j] = rel[j][i] = v;
				}
			}
		}
	}

	int minV = 100000, minP;
	for (int i = 1; i <= N; ++i) {
		int val = 0;
		for (int j = 1; j <= N; ++j) {
			val += rel[i][j];
		}
		if (minV > val) {
			minV = val;
			minP = i;
		}
	}

	cout << minP << "\n";

	return 0;
}