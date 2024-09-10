#include <iostream>
#include <map>

using namespace std;

void preorder(map<char, pair<char, char>> m, char r);
void inorder(map<char, pair<char, char>> m, char r);
void postorder(map<char, pair<char, char>> m, char r);

int main() {
	//freopen("input.txt", "r", stdin);

	int N;
	char p, lc, rc;
	scanf("%d", &N);
	map<char, pair<char, char>> m;
	for (int i = 0; i < N; i++) {
		scanf(" %c %c %c", &p, &lc, &rc);
		m[p] = make_pair(lc, rc);
	}

	preorder(m, 'A');
	puts("");
	inorder(m, 'A');
	puts("");
	postorder(m, 'A');
	puts("");

	return 0;
}

void preorder(map<char, pair<char, char>> m, char r) {
	char lc, rc;
	if (r == '.') return;
	
	printf("%c", r);
	preorder(m, m[r].first);
	preorder(m, m[r].second);
}

void inorder(map<char, pair<char, char>> m, char r) {
	char lc, rc;
	if (r == '.') return;

	inorder(m, m[r].first);
	printf("%c", r);
	inorder(m, m[r].second);
}

void postorder(map<char, pair<char, char>> m, char r) {
	char lc, rc;
	if (r == '.') return;
	
	postorder(m, m[r].first);
	postorder(m, m[r].second);
	printf("%c", r);
}