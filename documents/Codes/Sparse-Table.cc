#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, m, lg;
vector<int> a;
vector<vector<int>> st;
vector<int> log2n;

int main() {
	scanf("%d", &n);
	a.resize(n);
	log2n.resize(n + 1);
	log2n[1] = 0; log2n[2] = 1;
	for (int i = 3; i <= n; ++ i) {
		log2n[i] = log2n[i / 2] + 1;
	}

	lg = ceil(log2(n));
	st.assign(n, vector<int>(lg + 1));

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		st[i][0] = a[i];
	}
	for (int j = 1; j <= lg; ++ j) {
		for (int i = 0; i + (1 << j) - 1 < n; ++ i) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		int lg = log2n[r - l + 1];
		int mx = max(st[l][lg], st[r - (1 << lg) + 1][lg]);
		printf("%d\n", mx);
	}
}