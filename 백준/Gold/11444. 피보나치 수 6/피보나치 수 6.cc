#include <iostream>
#include <map>

#define INF 1'000'000'000'000'000'001;
using namespace std;

long long int n;
map<long long int, long long int> m;

long long int fibo(long long num) {
	if (!num) return 0;
	else if (num == 1) return 1;
	else if (m.count(num)) {
		return m[num];
	}
	else {
		if (num & 1) {
			long long int t1 = fibo((num + 1) / 2);
			long long int t2 = fibo((num - 1) / 2);
			return m[num] = (t1 * t1 + t2 * t2) % 1'000'000'007;
		}
		else {
			long long int t1 = fibo(num / 2);
			long long int t2 = fibo(num / 2 - 1);
			return m[num] = (t1 * t1 + 2 * t1 * t2) % 1'000'000'007;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	cout << fibo(n) << "\n";

	return 0;
}