#include <algorithm>
#include <climits>
#include <cstdio>
#define N 200005
using namespace std;

int t, q;

long long height(long long a, long long b, long long n) {
	if (n == 0) return 0;
	return (a - b) * (n - 1) + a;
}

long long day(long long a, long long b, long long h) {
	if (h == 0) return 0;
	if (h <= a) return 1;
	return (h - b - 1) / (a - b) + 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		long long lo = 0, hi = LLONG_MAX;
		scanf("%d", &q);

		for (int i = 0; i < q; ++ i) {
			int ty; long long a, b, n;
			scanf("%d", &ty);
		
			if (ty == 1) {
				scanf("%lld%lld%lld", &a, &b, &n);
				long long l = height(a, b, n - 1) + 1, h = height(a, b, n);
				if (hi < l || h < lo) {
					printf("0 ");
				} else {
					printf("1 ");
					lo = max(lo, l); hi = min(hi, h);
				}
			} else {
				scanf("%lld%lld", &a, &b);
				long long d1 = day(a, b, lo), d2 = day(a, b, hi);
				if (d1 == d2) {
					printf("%lld ", d1);
				} else {
					printf("-1 ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}