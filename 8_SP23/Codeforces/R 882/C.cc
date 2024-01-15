#include <cstdio>
#include <vector>
#include <limits>
#include <unordered_set>
#define BIT 8
using namespace std;

void solve() {
	int n, cur = 0;
	scanf("%d", &n);
	unordered_set<int> st{0};

	for (int i = 0; i < n; ++ i) {
		int a; scanf("%d", &a);
		cur = cur ^ a;
		st.insert(cur);
	}

	int cnt = 1, ans = 0;
	vector<vector<int>> trie((n + 5) * 8, vector<int>(2, 0));
	for (const int v : st) {
		int p = 0;
		for (int bit = 1 << BIT; bit; bit >>= 1) {
			int b = (bool) (v & bit);
			if (trie[p][b]) {
				p = trie[p][b];
			} else {
				p = trie[p][b] = cnt ++;
			}
		}
	}

	for (const int v : st) {
		int p = 0, cur = 0;
		for (int bit = 1 << BIT; bit; bit >>= 1) {
			int b = (bool) (v & bit);
			if (trie[p][!b]) {
				p = trie[p][!b];
				cur |= bit;
			} else {
				p = trie[p][b];
			}
		}
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}