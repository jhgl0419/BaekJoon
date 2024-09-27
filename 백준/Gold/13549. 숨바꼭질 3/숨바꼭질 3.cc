#include <iostream>
#include <queue>
#define INF 1'000'000

using namespace std;

int N, K;

int minT[100'001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;	// f: cost, s: end

int main() {
	scanf("%d %d", &N, &K);

	fill(minT, minT + 100'001, INF);
	minT[N] = 0;
	pq.push({ 0,N });
	while (!pq.empty()) {
		auto t = pq.top(); pq.pop();
        if (t.second == K) break;
		if (t.first > minT[t.second]) continue;

		if (t.second > 0) {
			if (minT[t.second - 1] > minT[t.second] + 1) {
				minT[t.second - 1] = minT[t.second] + 1;
				pq.push({ minT[t.second - 1], t.second - 1 });
			}
		}
		if (t.second > 0 && t.second <= 50'000) {
			if (minT[t.second * 2] > minT[t.second]) {
				minT[t.second * 2] = minT[t.second];
				pq.push({ minT[t.second * 2], t.second * 2 });
			}
		}
		if (t.second < 100'000) {
			if (minT[t.second + 1] > minT[t.second] + 1) {
				minT[t.second + 1] = minT[t.second] + 1;
				pq.push({ minT[t.second + 1], t.second + 1 });
			}
		}
	}

	printf("%d\n", minT[K]);
	return 0;
}