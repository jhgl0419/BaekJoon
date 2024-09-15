#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int D(int n) {
	return 2 * n % 10'000;
}

int S(int n) {
	return n == 0 ? 9'999 : n - 1;
}

int L(int n) {
	int d1 = n / 1000;
	int other = (n % 1000) * 10;

	return d1 + other;
}

int R(int n) {
	int d4 = (n % 10) * 1000;
	int other = n / 10;

	return d4 + other;
}

int visit[10'000];
queue<pair<int, string>> q;

int main() {
	int T;
	scanf("%d", &T);

	int A, B;

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &A, &B);
		memset(visit, 0, sizeof(visit));
		while (!q.empty()) q.pop();
		q.push({A, ""});

		while (!q.empty()) {
			auto t = q.front(); q.pop();
			if (t.first == B) {
				cout << t.second << "\n";
				break;
			}
			if (visit[t.first]) continue;
			visit[t.first] = 1;
			q.push({ D(t.first), t.second + "D" });
			q.push({ S(t.first), t.second + "S" });
			q.push({ L(t.first), t.second + "L" });
			q.push({ R(t.first), t.second + "R" });
		}
	}

	return 0;
}