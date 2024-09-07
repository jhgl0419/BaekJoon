// DP
#include <iostream>
#include <vector>
#define DEBUG

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	
	int n; scanf("%d", &n);
	vector<int> v[501];
	int tmp;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}

	int larger;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			larger = v[i + 1][j] > v[i + 1][j + 1] 
				? v[i + 1][j] : v[i + 1][j + 1];
			v[i][j] += larger;
		}
	}

	printf("%d\n", v[1][0]);
	return 0;
}