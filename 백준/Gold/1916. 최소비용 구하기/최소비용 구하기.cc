#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> buses;
int minCost[1'001];
int main() {
	int N; scanf("%d", &N);
	int M; scanf("%d", &M);
	buses.resize(N+1);
	
	int s, e, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &c);
		buses[s].push_back({e, c});
	}
	
	int start, end;
	scanf("%d %d", &start, &end);

	priority_queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		minCost[i] = INT_MAX;
	}
	minCost[start] = 0;
	q.push({0, start});
	while (!q.empty()) {
		auto t = q.top(); q.pop();

		if (minCost[t.second] < t.first) continue;

		for (auto i : buses[t.second]) {
			if (minCost[i.first] > minCost[t.second] + i.second) {
				minCost[i.first] = minCost[t.second] + i.second;
				q.push({minCost[i.first], i.first});
			}
		}
	}
	printf("%d\n", minCost[end]);

	return 0;
}