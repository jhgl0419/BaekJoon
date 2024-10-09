#include <iostream>
#include <vector>

using namespace std;

int V;
vector<pair<int, int>> edges[100'001];
int visit[100'001];
int maxIdx;
int maxDist;

void bt(int n, int len) {
	visit[n] = 1;
	if (maxDist < len) {
		maxDist = len;
		maxIdx = n;
	}

	for (auto i : edges[n]) {
		if (visit[i.first]) continue;

		bt(i.first, len + i.second);
		visit[i.first] = 0;
	}
}

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> V;
	int u, v, c;
	for (int i = 0; i < V; i++) {
		cin >> u;
		while (1) {
			cin >> v;
			if (v == -1) break;
			
			cin >> c;
			edges[u].push_back({ v,c });
		}
	}

	maxDist = 0;
	bt(1, 0);
	visit[1] = 0;

	maxDist = 0;
	bt(maxIdx, 0);

	cout << maxDist;

	return 0;
}