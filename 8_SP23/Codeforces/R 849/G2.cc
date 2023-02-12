#include <cstdio>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int a[200005], idx[200005];
pair<int,int> v[200005];
long long s[200005];

void solve() {
	int n, c, ans = 0;
	scanf("%d%d", &n, &c);

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		v[i].first = a[i] + min(i, n + 1 - i); v[i].second = i;
	}
	sort(v + 1, v + n + 1);
	for (int i = 1; i <= n; ++ i) {
		s[i] = s[i - 1] + v[i].first;
		idx[v[i].second] = i;

		// printf("i: %d %d\n", v[i].first, v[i].second);
	}

	// for (int i = 1; i <= n; ++ i) {
	// 	printf("%d ", idx[i]);
	// }
	// printf("\n");
	// for (int i = 1; i <= n; ++ i) {
	// 	printf("%d ", s[i]);
	// }
	// printf("\n");

	for (int i = 1; i <= n; ++ i) {
		int remaining = c - a[i] - i;
		if (remaining < 0) continue;
		long long * it = upper_bound(s + 1, s + n + 1, remaining);
		int j = it - s;
		if (remaining < s[j] || j > n) -- j;
		// printf("  %d) remaining: %d; j: %d\n", i, remaining, j);
		if (j < idx[i]) {
			ans = max(j + 1, ans);
		} else {
			remaining += v[idx[i]].first;
			it = upper_bound(s + 1, s + n + 1, remaining);
			j = it - s;
			if (remaining < s[j] || j > n) -- j;
			// printf("  %d) remaining: %d; j: %d\n", i, remaining, j);
			ans = max(j, ans);
		}
	}

	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}