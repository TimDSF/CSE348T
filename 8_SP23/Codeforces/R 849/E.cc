#include <cstdio>
#include <algorithm>
using namespace std;

int a[200005];

void solve() {
	int n, cnt_ne = 0, mn = 0x7fffffff;
	long long sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		if (a[i] < 0) {
			++ cnt_ne;
			a[i] = - a[i];
		}
		sum += (long long) a[i];
		mn = min(a[i], mn);
	}

	if (cnt_ne % 2 == 0) {
		printf("%lld\n", (long long) sum);
	} else {
		printf("%lld\n", (long long) sum - mn * 2);
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}