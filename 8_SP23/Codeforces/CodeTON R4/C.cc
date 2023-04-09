#include <algorithm>
#include <cstdio>
#define N 200005
using namespace std;

int t, n;
long long c, d;
int a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld%lld", &n, &c, &d);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + 1 + n);

		int r = 0;
		long long ans = c * n + d;
		for (int i = 1; i <= n; ++ i) {
			if (a[i - 1] == a[i]) ++ r;
			long long cost = c * (n - i + r) + d * (a[i] - (i - r));
			ans = min(ans, cost);
		}
		printf("%lld\n", ans);
	}
	return 0;
}