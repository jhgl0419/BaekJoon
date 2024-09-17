#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> r1;
vector<vector<pair<int, int>>> r2;
int min1[1'001];
int min2[1'001];
int main() {
	int N, M, X; scanf("%d %d %d", &N, &M, &X);
	int s, e, c;
	r1.resize(N + 1); r2.resize(N + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &c);
		r1[s].push_back({ e, c });
		r2[e].push_back({ s, c });
	}

	for (int i = 1; i <= N; i++) {
		min1[i] = INT_MAX;
		min2[i] = INT_MAX;
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, X });
	min1[X] = 0;
	while (!pq.empty()) {
		auto t = pq.top(); pq.pop();
		
		if (min1[t.second] < t.first) continue;

		for (auto i : r1[t.second]) {
			if (min1[i.first] > t.first + i.second) {
				min1[i.first] = t.first + i.second;
				pq.push({min1[i.first], i.first});
			}
		}
	}

	pq.push({ 0, X });
	min2[X] = 0;
	while (!pq.empty()) {
		auto t = pq.top(); pq.pop();

		if (min2[t.second] < t.first) continue;

		for (auto i : r2[t.second]) {
			if (min2[i.first] > t.first + i.second) {
				min2[i.first] = t.first + i.second;
				pq.push({ min2[i.first], i.first });
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		max = min1[i] + min2[i] > max ? min1[i] + min2[i] : max;
	}
	printf("%d\n", max);

	return 0;
}