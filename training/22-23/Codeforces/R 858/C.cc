#include <cstdio>
#include <cmath>
using namespace std;
 
int t, n, N, a[400005];
int main(){
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		N = n << 1;
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &a[i]);
		}
		long long mn = 0x7fffffffffffffff;
		if (n == 1) {
			long long m = (a[0] + a[1]) / 2;
			printf("%lld\n", (long long) abs(a[0] - m) + abs(a[1] - m));
			continue;
		} else if (n == 2) {
			long long m = (long long) abs(a[0] - 2) + abs(a[1] - 2) + abs(a[2] - 2) + abs(a[3] - 2);
			mn = min(mn, m);
		}
		
		{
			long long m = 0;
			for (int i = 0; i < N; ++ i) {
				m += abs(a[i]);
			}
			mn = min(mn, m);
		}

		if (n % 2 == 0) {
			long long m = 0, mx = 0x8000000000000000;
			for (int i = 0; i < N; ++ i) {
				m += abs(a[i] + 1);
				mx = max((long long) a[i], mx);
			}
			m -= abs(mx + 1);
			m += abs(mx - n);
			mn = min(mn, m);
		}

		printf("%lld\n", mn);
	}
	return 0;
}
