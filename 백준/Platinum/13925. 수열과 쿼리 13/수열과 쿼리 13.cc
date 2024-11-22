#include<iostream>
#include<vector>
#include<cmath>
#define MOD 1'000'000'007

using namespace std;

typedef long long LL;

int N, M;
int nums[100'001];

vector<LL> Seg;
vector<LL> lazy_add;
vector<LL> lazy_prod;

void init(int, int, int);
void update(int, int, int, int, int, int, int);
void update_lazy(int, int, int);
LL query(int, int, int, int, int);

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	int cnt = 1 << ((int)ceil(log2(N)) + 1);
	Seg.resize(cnt);
	lazy_add.resize(cnt);
	lazy_prod.resize(cnt, 1);

	init(1, 1, N);

	cin >> M;
	int cmd, x,y,v;
	while (M--) {
		cin >> cmd >> x >> y;
		switch (cmd) {
		case 1:
			cin >> v;
			update(1, 1, N, x, y, 1, v);
			break;
		case 2:
			cin >> v;
			update(1, 1, N, x, y, 2, v);
			break;
		case 3:
			cin >> v;
			update(1, 1, N, x, y, 3, v);
			break;
		case 4:
			cout << query(1, 1, N, x, y) << "\n";
			break;
		default:
			break;
		}
	}
	return 0;
}

void init(int node, int start, int end) {
	if (start == end) {
		Seg[node] = nums[start];
		return;
	}

	int mid = (start + end) / 2;
	int lc = node << 1;
	int rc = lc + 1;

	init(lc, start, mid);
	init(rc, mid + 1, end);

	Seg[node] = (Seg[lc] + Seg[rc]) % MOD;
}

void update(int node, int start, int end, int L, int R, int method, int val) {
	update_lazy(node, start, end);

	if (end < L || R < start) return;

	int lc = node << 1;
	int rc = lc + 1;
	if (L <= start && end <= R) {
		switch (method) {
		case 1:	// add
			Seg[node] = (Seg[node] + ((LL)(end - start + 1) * (LL)val)) % MOD;
			if (start != end) {
				lazy_add[lc] = (lazy_add[lc] + val) % MOD;
				lazy_add[rc] = (lazy_add[rc] + val) % MOD;
			}
			break;

		case 2:	// product
			Seg[node] = (Seg[node] * val) % MOD;
			if (start != end) {
				lazy_add[lc] = (lazy_add[lc] * val) % MOD;
				lazy_add[rc] = (lazy_add[rc] * val) % MOD;
				lazy_prod[lc] = (lazy_prod[lc] * val) % MOD;
				lazy_prod[rc] = (lazy_prod[rc] * val) % MOD;
			}
			break;
		
		case 3:
			Seg[node] = ((LL)(end - start + 1) * (LL)val) % MOD;
			if (start != end) {
				lazy_add[lc] = val;
				lazy_add[rc] = val;
				lazy_prod[lc] = 0;
				lazy_prod[rc] = 0;
			}
			break;

		default:
			break;
		}
		
		return;
	}
	int mid = (start + end) / 2;
	update(lc, start, mid, L, R, method, val);
	update(rc, mid + 1, end, L, R, method, val);

	Seg[node] = (Seg[lc] + Seg[rc]) % MOD;
}

void update_lazy(int node, int start, int end) {
	// product after addition
	if (!lazy_add[node] && lazy_prod[node] == 1) return;
	Seg[node] = ((Seg[node] * lazy_prod[node]) % MOD + (LL)(end - start + 1) * lazy_add[node]) % MOD;

	int lc = node << 1;
	int rc = lc + 1;
	if (start != end) {
		lazy_add[lc] = ((lazy_add[lc] * lazy_prod[node]) % MOD + lazy_add[node]) % MOD;
		lazy_add[rc] = ((lazy_add[rc] * lazy_prod[node]) % MOD + lazy_add[node]) % MOD;
		lazy_prod[lc] = (lazy_prod[lc] * lazy_prod[node]) % MOD;
		lazy_prod[rc] = (lazy_prod[rc] * lazy_prod[node]) % MOD;
	}
	lazy_add[node] = 0;
	lazy_prod[node] = 1;	
}

LL query(int node, int start, int end, int L, int R) {
	update_lazy(node, start, end);

	if (end < L || R < start) return 0;
	if (L <= start && end <= R) {
		return Seg[node];
	}

	int mid = (start + end) / 2;
	int lc = node << 1;
	int rc = lc + 1;
	return (query(lc, start, mid, L, R) + query(rc, mid + 1, end, L, R)) % MOD;
}