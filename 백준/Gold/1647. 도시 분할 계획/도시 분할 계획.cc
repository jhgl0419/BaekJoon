#include <iostream>
#include <vector>
#include <algorithm>

// 두 마을의 유지비 합의 최소 => MST 구성하고 MST 중 가장 가중치가 큰 간선 지우기
using namespace std;

typedef pair<int, pair<int, int>> PP;

bool CMP(PP a, PP b) {
	return a.first < b.first;
}

int root[100'001];

int getParent(int a) {
	if (root[a] == a) {
		return a;
	}

	return root[a] = getParent(root[a]);
}

void UnionSet(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);

	if (pa < pb) root[pb] = pa;
	else root[pa] = pb;

}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	vector<PP> edges;	// f: cost, s.f: start, s.s: end
	int A, B, C;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		edges.push_back({ C, {A, B} });
	}
	sort(edges.begin(), edges.end(), CMP);
	for (int i = 1;i <= N; i++) {
		root[i] = i;
	}
	int cnt = 0, idx = 0, sum = 0, max = 0;
	while (cnt < N - 1) {
		auto t = edges[idx++];
		if (getParent(t.second.first) == getParent(t.second.second)) continue;

		UnionSet(t.second.first, t.second.second);
		cnt++;
		sum += t.first;
		max = t.first;
	}
	printf("%d\n", sum - max);
	return 0;
}