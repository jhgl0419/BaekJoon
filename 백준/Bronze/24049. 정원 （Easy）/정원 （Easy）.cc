#include <iostream>

using namespace std;

int garden[1'001][1'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> garden[i][0];
    for (int i = 1; i <= M; i++) cin >> garden[0][i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M;j++) {
            garden[i][j] = garden[i - 1][j] ^ garden[i][j - 1];
        }
    }

    cout << garden[N][M] << "\n";
    return 0;
}