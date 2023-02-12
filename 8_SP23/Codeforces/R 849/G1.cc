#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

void solve() {
	int n, c, a, ans = 0;
	scanf("%d%d", &n, &c);

	priority_queue< int, vector<int>, greater<int> > q;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a);
		a += i;
		q.push(a);
	}

	while (!q.empty()) {
		int a = q.top(); q.pop();
		if (c >= a) {
			c -= a;
			++ ans;
		} else {
			break;
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