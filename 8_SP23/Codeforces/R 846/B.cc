#include <numeric>
#include <cstdio>
#include <cmath>

using namespace std;

int T, n, a[200005];

long long _gcd_(long long a, long long b) {
	long long c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main(){
	scanf("%d", &T);

	while (T--) {
		long long sum = 0, ans = 0, cur = 0;

		scanf("%d", &n);
		
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}


		for (int j = 0; j < n - 1; ++ j) {
			cur += a[j];
			ans = max(_gcd_(cur, sum - cur), ans);
		}

		printf("%lld\n", ans);
	}

	return 0;
}