#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, m, prev, curr, sum = 0;
	scanf("%d%d", &n, &m);

	vector<int> v(n - 1);
	scanf("%d", &prev);
	for (int i = 0; i < n - 1; ++ i) {
		scanf("%d", &curr);
		v[i] = abs(curr - prev);
		prev = curr;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n - m; ++ i) {
		sum += v[i];
	}

	printf("%d\n", sum);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}