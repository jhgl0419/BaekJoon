#include <iostream>
#include <algorithm>
#define MAX_N 14
#define INF 10'000'000
//#define DEBUG

using namespace std;

int N, M;
int P[MAX_N + 1]; // idx: 1~N

int cost[MAX_N + 2][MAX_N + 2]; // idx: 1 ~ N+1

int dp[1 << (MAX_N + 1)][MAX_N + 2];	
// if N = 2 [ob111][3] 까지 가능. => [1 << 3][4]
// i상태에서 p번째 동네 방문 => [i | 1 << (p-1)][p]

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {	// N번
		scanf("%d", &P[i]);
	}

	fill(&cost[0][0], &cost[MAX_N + 1][MAX_N + 2], INF);
    int u, v, c;
    for (int i = 0; i < M; i++) {	// M번  
		scanf("%d %d %d", &u, &v, &c);
		cost[u][v] = min(cost[u][v], c);
	}
    
	fill(&dp[0][0], &dp[(1 << (MAX_N + 1)) - 1][MAX_N + 2], INF);
	int init_status = 1 << N;	// N이 2일 때 100가 처음
	int last_status = (1 << (N + 1)) - 1;	// N이 2일 때 111가 마지막

	// N+1에서 시작하여 모든 동네 한 번씩만 방문하고 마지막에 N+1까지 거리 더해 최소 계산.
	dp[init_status][N + 1] = 0;
	for (int i = 1; i <= N; i++) {
		if (P[i] == i) {
			dp[init_status | (1 << (i - 1))][i] = cost[N + 1][i];
		}
	}
    
	for (int i = init_status; i <= last_status; i++) {
		for (int j = 1; j <= N; j++) {	// N+1은 포함되면 안됨.
			if (i & (1 << (j - 1))) {	// 상태에 포함된 경우만 마지막 방문 동네일 수 있음
				for (int k = 1; k <= N; k++) {
					if (i & (1 << (k - 1))) continue;	// 현재 상태에 없는 동네만
					if ((P[k] == k) || (i & (1 << (P[k] - 1)))) {		// 선행조건 만족 시
						dp[i | (1 << (k - 1))][k] = min(dp[i | (1 << (k - 1))][k], dp[i][j] + cost[j][k]);
					}
				}
			}
		}
	}
    
	int answer = INF;
	for (int i = 1; i <= N; i++) {
		int cmpVal = dp[last_status][i] + cost[i][N + 1];
		answer = min(answer, cmpVal);
	}
	printf("%d\n", (answer < INF) ? answer : -1);

	return 0;
}