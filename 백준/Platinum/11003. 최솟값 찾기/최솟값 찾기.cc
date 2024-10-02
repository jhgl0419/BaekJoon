#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N, L;
	cin >> N >> L;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pq.push({ tmp, i });
        while ((i - pq.top().second) >= L) {
			pq.pop();
		}
		cout << pq.top().first << " ";
	}
	
	return 0;
}