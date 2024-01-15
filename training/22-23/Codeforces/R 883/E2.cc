#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

long long fpow(long long a, long long b) {
	if (b == 0) return 1; 
	if (b == 1) return a;
 	long long tmp = pow(a, b / 2);
 	tmp *= tmp;
 	if (b % 2) tmp *= a;
 	return tmp;
}

void solve() {
	long long n; scanf("%lld", &n);
	for (int m = 2; m < 64; ++ m) {
		long long l = 2, r = floor(pow(n, 1.0 / m));
		printf("%lld %lld\n", l, r);

		while (l <= r) {
			int k = (l + r) / 2;
			printf("  %d\n", k);
			long long s = (fpow(k, m + 1) - 1) / (k - 1);
			if (s == n) {
				printf("YES\n");
				return;
			} else if (s < n) {
				l = k + 1;
			} else {
				r = k - 1;
			}
		}
	}
	printf("NO\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}