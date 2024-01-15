#include <cmath>
#include <cstdio>
#include <vector>
#define MOD 1000000007
using namespace std;

int n, m;

inline int add(const int a, const int b) {
	const int tmp = a + b;
	return (tmp >= MOD) ? (tmp - MOD) : tmp;
}

int main() {
	int ans = 0;
	scanf("%d%d", &n, &m);
	const int sq = (int) sqrt(n * 2) + 1;
	vector<int> a(n, 0);
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(2 * sq + 1, vector<int>(m + 1, 0)));
	
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
	}

	dp[0][sq][0] = 1;

	for (int ii = 0; ii < n; ++ ii) {
		int i = ii & 1;
		int ni = i ^ 1;
		dp[ni] = vector<vector<int>>(2 * sq + 1, vector<int>(m + 1, 0));
		for (int j = 0; j <= 2 * sq; ++ j) {
			for (int k = 0; k <= m; ++ k) {
				if (dp[i][j][k] == 0) continue;
				for (int z = 0; z < 2; ++ z) {
					int nj = j + z - a[ii];
					int nk = k + abs(nj - sq);
					if (nk <= m) dp[ni][nj][nk] = add(dp[ni][nj][nk], dp[i][j][k]);
				}
			}
		}
	}

	for (int k = m % 2; k <= m; k += 2) {
		ans = add(ans, dp[n & 1][sq][k]);
	}

	printf("%d\n", ans);
	return 0;
}