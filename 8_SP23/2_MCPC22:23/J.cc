#include <cstring>
#include <cstdio>
using namespace std;

const int MOD = 998244353;
int n, m, q;
char a[10][10];
bool v[10][10];
long long ans, p[65];

inline bool check(int i, int j) {
	if (v[i][j] || v[i][j + 1] || v[i + 1][j] || v[i + 1][j + 1]) return false;
	if (a[i][j] != '?' && a[i][j] != 'I') return false; 
	if (a[i][j + 1] != '?' && a[i][j + 1] != 'C') return false; 
	if (a[i + 1][j] != '?' && a[i + 1][j] != 'P') return false;
	if (a[i + 1][j + 1] != '?' && a[i + 1][j + 1] != 'C') return false; 
	return true;
}

void dfs(int i, int j, int cnt, int used) {
	if (i == n - 1) {
		if (cnt == 0) return;
		if (cnt % 2 == 0) {
			ans = (ans + MOD - p[q - used]) % MOD;
		} else {
			ans = (ans + p[q - used]) % MOD;
		}
		return;
	}
	if (j == m - 1) {
		dfs(i + 1, 0, cnt, used);
		return;
	}

	dfs(i, j + 1, cnt, used);
	if (check(i, j)) {
		v[i][j] = v[i][j + 1] = v[i + 1][j] = v[i + 1][j + 1] = true;
		used += (a[i][j] == '?') + (a[i][j + 1] == '?') + (a[i + 1][j] == '?') + (a[i + 1][j + 1] == '?');
		dfs(i, j + 1, cnt + 1, used);
		v[i][j] = v[i][j + 1] = v[i + 1][j] = v[i + 1][j + 1] = false;
	}
}

int main() {
	scanf("%d%d", &n, &m); getchar();
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			scanf("%c", &a[i][j]);
			if (a[i][j] == '?') ++ q;
		}
		getchar();
	}

	p[0] = 1;
	for (int i = 1; i <= 64; ++ i) {
		p[i] = p[i - 1] * 3 % MOD;
	}

	dfs(0, 0, 0, 0);

	printf("%lld\n", ans);

	return 0;
}