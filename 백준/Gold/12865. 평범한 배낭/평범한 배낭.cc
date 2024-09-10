#include <iostream>
#include <vector>
#include <cstring>
#define MAX(a,b) (a > b ? a : b)
// 트리 지름 == 정점 사이 거리 중 가장 긴 것

using namespace std;

struct Item {
	int W;
	int V;
};

int memo[100][100'001];

int get_max(vector<Item> items, int limit, int start, int N) {
	if (start >= N)
		return 0;
    
    if (memo[start][limit] != -1)
		return memo[start][limit];
	
	if (limit < items[start].W) {
		return memo[start][limit] = get_max(items, limit, start + 1, N);
	}

	int non_incl = get_max(items, limit, start + 1, N);
	int incl = get_max(items, limit - items[start].W, start + 1, N) + items[start].V;
	
	return memo[start][limit] = MAX(non_incl, incl);
}

int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);

	int N, K;
	scanf("%d %d", &N, &K);
	memset(memo, -1, sizeof(memo));

	vector<Item> items;
	int w, v;
	for (int l = 0; l < N; l++) {
		scanf("%d %d", &w, &v);
		Item new_one;
		new_one.W = w; new_one.V = v;
		items.push_back(new_one);
	}

	printf("%d\n", get_max(items, K, 0, N));

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}