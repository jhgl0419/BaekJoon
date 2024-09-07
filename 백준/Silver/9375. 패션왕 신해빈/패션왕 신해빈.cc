#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {

	int T;
	cin >> T;

	int n, count;
	map<string, int> m;
	string name, type;
	for (int test_case = 1; test_case <= T; test_case++) {
		m = {};
		count = 1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> type;
			m[type]++;
		}
		for (auto& t : m) {
			count *= t.second + 1;
		}
		cout << count - 1 << "\n";
	}

	return 0;
}