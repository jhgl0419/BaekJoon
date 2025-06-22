#include <iostream>
#include <algorithm>

using namespace std;

int nums[20'001];

int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, A, D;
    cin >> N >> A >> D;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int i = 0;
    for (; i < N; i++) {
        if (nums[i] == A) {
            cnt++;
            break;
        }
    }
    if (i == N) {
        cout << 0 << "\n";
    }
    else {
        int target = A + D;
        for (; i < N; i++) {
            if (target == nums[i]) {
                cnt++;
                target += D;
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}