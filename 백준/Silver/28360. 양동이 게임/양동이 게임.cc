#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // 이게 핵심!

using namespace std;

int N, M;
vector<int> child[51];
int parentCnt[51];
int childCnt[51];
double water[51];

void flow() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!parentCnt[i]) q.push(i);
    }
    while (!q.empty()) {
        int t = q.front(); q.pop();

        if (childCnt[t]) {
            double amount = water[t] / childCnt[t];

            for (auto c : child[t]) {
                water[c] += amount;
                parentCnt[c]--;
                if (parentCnt[c] == 0) q.push(c);
            }

            water[t] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        parentCnt[w]++;
        child[v].push_back(w);
        childCnt[v]++;
    }

    water[1] = 100;
    flow();

    double max_w = 0;
    for (int i = 1; i <= N; i++) {
        if (max_w < water[i]) max_w = water[i];
    }

    cout << fixed << setprecision(10) << max_w << "\n";
    return 0;
}
