#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

inline int D(int n) {
	return 2 * n % 10'000;
}

inline int S(int n) {
	return n == 0 ? 9'999 : n - 1;
}

inline int L(int n) {
	int d1 = n / 1000;
	int other = (n % 1000) * 10;

	return d1 + other;
}

inline int R(int n) {
	int d4 = (n % 10) * 1000;
	int other = n / 10;

	return d4 + other;
}

int visit[10'000];
queue<pair<int, string>> q;

int main() {
	int T;
	scanf("%d", &T);

	int A, B, d, s, l, r;

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

			d = D(t.first);
            s = S(t.first);
            l = L(t.first);
            r = R(t.first);
            if(!visit[d]) {
                q.push({ d, t.second + "D" });
                visit[d] = 1;
            }
            if(!visit[s]) {
                q.push({ s, t.second + "S" });
                visit[s] = 1;
            }
            if(!visit[l]) {
                q.push({ l, t.second + "L" });
                visit[l] = 1;
            }
            if(!visit[r]) {
                q.push({ r, t.second + "R" });
                visit[r] = 1;
            }
		}
	}

	return 0;
}