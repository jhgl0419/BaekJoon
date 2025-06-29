#include <iostream>

// 1/12 * n(n-1)(2n-4)

using namespace std;

long long n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    long long res = n * (n - 1) * (2 * n - 4) / 12;

    cout << res << "\n" << 3 << "\n";

    return 0;
}
