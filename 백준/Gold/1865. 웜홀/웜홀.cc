#include <iostream>
#include <vector>
#include <queue>
#define INF 1'000'000'000

using namespace std;

int TC;
int N, M, W;
int S, E, T;

int dist[501][501];
int min_d[501];

bool solution() {
	vector<pair<int, int>> edge;
	fill(&dist[0][0], &dist[500][501], 0);
	fill(min_d, min_d + 501, INF);
	cin >> N >> M >> W;
	
	for (int i = 0; i < M; ++i) {
		cin >> S >> E >> T;
		if (!dist[S][E]) {
			dist[S][E] = T;
			edge.push_back({ S, E });
			dist[E][S] = T;
			edge.push_back({ E, S });
		}
		else if (dist[S][E] > T) {
			dist[S][E] = T;
			dist[E][S] = T;
		}
	}
	for (int i = 0; i < W; ++i) {
		cin >> S >> E >> T;
		if (!dist[S][E]) {
			dist[S][E] = -T;
			edge.push_back({ S, E });
		}
		else if (dist[S][E] > -T) {
			dist[S][E] = -T;
		}
	}

	for (int i = 1; i < N; ++i) {
		for (auto j : edge) {
			if (min_d[j.second] > min_d[j.first] + dist[j.first][j.second]) {
				min_d[j.second] = min_d[j.first] + dist[j.first][j.second];
			}
		}
	}
	for (auto j : edge) {
		if (min_d[j.second] > min_d[j.first] + dist[j.first][j.second]) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		bool res = solution();

		cout << (res ? "YES" : "NO") << "\n";
	}

	return 0;
}