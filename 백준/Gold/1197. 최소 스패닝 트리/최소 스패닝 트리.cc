#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int minCost[10'001];
int visit[10'001];
vector<vector<pair<int, int>>> edges;    // index: start, f: end, s: cost

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    edges.clear();
    edges.resize(V + 1);
    for (int i = 1; i <= V; i++) {
        minCost[i] = 1'000'001;
    }
    memset(visit, 0, sizeof(visit));

    int A, B, C;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &A, &B, &C);
        edges[A].push_back({ B,C });
        edges[B].push_back({ A,C });
    }

    minCost[1] = 0;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        auto t = pq.top(); pq.pop();    // f: cost, s: end 
        visit[t.second] = 1;

        for (auto i : edges[t.second]) {
            if (visit[i.first]) continue;
            if (minCost[i.first] > i.second) {
                pq.push({ i.second, i.first });
                minCost[i.first] = i.second;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= V; i++) {
        sum += minCost[i];
    }
    printf("%d\n", sum);

    return 0;
}