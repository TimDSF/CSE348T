#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	double d, h; scanf("%d%lf%lf", &n, &d, &h);
	vector<int> hi(n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &hi[i]);
	}
	double a = d * h / 2, ans = a;
	for (int i = n - 2; i >= 0; -- i) {
		double l = hi[i + 1] - hi[i];
		if (l >= h) {
			ans += a;
		} else {
			l = h - l;
			ans += a * (1 - l * l / h / h);
		}
	}
	printf("%lf\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}