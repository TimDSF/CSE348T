#include <algorithm>
#include <cstdio>

#define MOD 1000000007

using namespace std;

int n, a[3005];
long long pow2[3005];

void solve() {
	scanf("%d", &n);

	pow2[0] = 1;
	pow2[1] = 2;
	for (int i = 2; i <= n; ++ i) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}

	long long ans = (pow2[n] + MOD - 1 - n) % MOD;

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
	}
	a[n] = 0x7fffffff;

	for (int i = 1; i < n - 2; ++ i) {
		int l = i, r = i;

		for (int j = i + 1; j < n - 1; ++ j) {
			int d = a[j] - a[i];

			while (l >= 0 && a[i] - a[l] <= d) {
				-- l;
			}
			while (a[r] - a[j] < d) {
				++ r;
			}


			int l1 = i - l - 1;
			int r1 = r - j - 1;

			int l2 = i - l1;
			int r2 = n - 1 - j - r1;

			if (l1 != 0 && r1 != 0) {
				ans = (   ans 
						+ (pow2[l1] + MOD - 1) % MOD * (pow2[r1] + MOD - 1) % MOD * (pow2[l2 + r2]) % MOD
					  ) % MOD;
			}
		}
	}

	printf("%lld\n", ans);
}

int main() {
	solve();
	return 0;
}