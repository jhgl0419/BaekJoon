#include <iostream>
#include <algorithm>
#define INF 200'000
using namespace std;

int N, M, R;

int items[101];
int dist[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	fill(&dist[0][0], &dist[100][101], INF);
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		cin >> items[i];
	}
	int a, b, l;
	for (int i = 0; i < R; i++) {
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (dist[i][k] == INF) continue;

			for (int j = 1; j <= N; j++) {
				if (dist[k][j] == INF) continue;
				
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int max_v = 0;
	int sum;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j || dist[i][j] <= M) {
				sum += items[j];
			}
		}
		max_v = max(max_v, sum);
	}

	cout << max_v << "\n";

	return 0;
}