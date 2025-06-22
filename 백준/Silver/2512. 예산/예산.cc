#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int budgets[10'001];

bool test(int v) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (budgets[i] > v) {
            total += v;
        }
        else {
            total += budgets[i];
        }
    }
    if (total > M) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    int start = 1, end = 1;
    for (int i = 0; i < N; i++) {
        cin >> budgets[i];
        if (end < budgets[i]) end = budgets[i];
    }
    cin >> M;

    while (start < end) {
        int mid = (start + end + 1) / 2;

        if (test(mid)) {
            start = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << start << "\n";

    return 0;
}