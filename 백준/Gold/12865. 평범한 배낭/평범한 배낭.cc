#include <iostream>
#include <vector>
#include <cstring>
#define MAX(a,b) (a > b ? a : b)

using namespace std;

struct Item {
	int W;
	int V;
};

int memo[100'001];

int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);

	int N, K;
	scanf("%d %d", &N, &K);
	memset(memo, 0, sizeof(memo));

	vector<Item> items;
	int w, v;
	for (int l = 0; l < N; l++) {
		scanf("%d %d", &w, &v);
		Item new_one;
		new_one.W = w; new_one.V = v;
		items.push_back(new_one);
	}
	
	for (int i = 0; i < N; i++) {
		w = items[i].W;
		for (int limit = K; limit >= w; limit--) {
			memo[limit] = MAX(memo[limit], memo[limit - w] + items[i].V);
		}
	}

	printf("%d\n", memo[K]);
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}