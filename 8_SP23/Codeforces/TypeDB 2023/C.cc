#include <cstdio>
#include <limits>
#include <vector>
#include <utility>
#include <unordered_map>
#include <string.h>
using namespace std;

inline long long min(long long a, long long b) {
	return a > b ? b : a;
}

inline long long min(long long a, long long b, long long c) {
	return min(min(a, b), c);
}

long long a[200005][2];
long long dp[2][2];

void solve() {
	int n, s;
	memset(a, 0, sizeof(a));
	memset(dp, 0x7f, sizeof(dp));

	// vector<vector<long long>> a(n + 1, vector<long long>(2, 0));
	// vector<vector<long long>> dp(2, vector<long long>(2, 0x3fffffffffffffff));

	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++ i) {
		long long x;
		scanf("%lld", &x);
		if (x <= s * 2){
			a[i][0] = min(x, s);
		} else {
			a[i][0] = s;
		}
		a[i][1] = x - a[i][0];
	}

	a[1][1] = a[1][0] + a[1][1]; a[1][0] = 0;
	a[n][0] = a[n][0] + a[n][1]; a[n][1] = 0;

	dp[1][0] = 0;
	for (int i = 2; i <= n; ++ i) {
		long long lolo = dp[1 - i % 2][0] + a[i - 1][1] * a[i][0];
		long long hilo = dp[1 - i % 2][1] + a[i - 1][0] * a[i][0];

		dp[i % 2][0] = min(lolo, hilo);

		long long lohi = dp[1 - i % 2][0] + a[i - 1][1] * a[i][1];
		long long hihi = dp[1 - i % 2][1] + a[i - 1][0] * a[i][1];

		dp[i % 2][1] = min(lohi, hihi);
	}

	printf("%lld\n", dp[n % 2][0]);

	return;
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}