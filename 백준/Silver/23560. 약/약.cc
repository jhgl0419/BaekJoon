#include <iostream>
#include <algorithm>

using namespace std;

int N;
int drug[50];

int cnt = 0;
void take(int i, int j, int prev) {
    if (i == j) {
        cnt++;
        return;
    }

    if (prev == 0) {
        if (i % 3 == 1) {
            take(i + 1, j, 1);
        }
        if (j % 3 == 1) {
            take(i, j - 1, 1);
        }
    }
    else if (prev == 1) {
        if (i % 3 == 0 || i % 3 == 2) {
            take(i + 1, j, 2);
        }
        if (j % 3 == 0 || j % 3 == 2) {
            take(i, j - 1, 2);
        }
    }
    else if (prev == 2) {
        if (i % 3 == 0 || i % 3 == 2) {
            take(i + 1, j, 0);
        }
        if (j % 3 == 0 || j % 3 == 2) {
            take(i, j - 1, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    int N3 = N * 3;
    for (int i = 0; i < N3; i++) {
        drug[i] = i % 3;    // 아침 0 점심 1 저녁 2
    }

    take(0, N3 - 1, 2);

    cout << cnt << "\n";

    return 0;
}
