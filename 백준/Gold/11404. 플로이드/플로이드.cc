#include <iostream>
#include <climits>

using namespace std;

int minCost[101][101];

int main() {
	int n; scanf("%d", &n);
	int m; scanf("%d", &m);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			minCost[i][j] = INT_MAX;
		}
		minCost[i][i] = 0;
	}
	int s, e, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &c);
		if(minCost[s][e] > c)
			minCost[s][e] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
                if(minCost[i][k] + minCost[k][j] < 0) continue;// overflow
				if (minCost[i][j] > minCost[i][k] + minCost[k][j]) {
					minCost[i][j] = minCost[i][k] + minCost[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", minCost[i][j] == INT_MAX ? 0 : minCost[i][j]);
		}
		puts("");
	}

	return 0;
}