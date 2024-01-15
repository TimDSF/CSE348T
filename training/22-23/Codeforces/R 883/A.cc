#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a - b > 0) ++ ans;
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}