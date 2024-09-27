#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		pq.push(tmp);
	}
	int sum = 0;
    
	while (pq.size() > 1) {
		auto t1 = pq.top(); pq.pop();
		auto t2 = pq.top(); pq.pop();
		sum += tmp = t1 + t2;
		pq.push(tmp);
	}
	printf("%d\n", sum);
	
	return 0;
}