#include <iostream>
#include <algorithm>

using namespace std;

int N, X;

int As[100'001];
int Bs[100'001];
int subs[100'001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> X;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> As[i] >> Bs[i];
        subs[i] = As[i] - Bs[i];
        sum += As[i];
    }
    
    sort(subs, subs + N);
    
    int cost = 5'000 * N;
    int i = 0;
    for (; i < N; i++) {
        if (subs[i] < 0) {
            sum -= subs[i];
            cost -= 4'000;
        }
        else {
            break;
        }
    }

    while (cost > X) {
        sum -= subs[i];
        cost -= 4'000;

        i++;
    }

    cout << sum << "\n";

    return 0;
}
