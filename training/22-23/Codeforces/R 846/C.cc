#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

int T, n, m, a[2005], s;

int main(){
	scanf("%d", &T);

	while (T--) {
		int s, x, ans = 0;
		priority_queue<int> A, S;
		memset(a, 0, sizeof(a));

		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &x);
			++ a[x];
		}
		for (int i = 1; i <= n; ++ i) {
			if (a[i] != 0) A.push(a[i]);
		}
		for (int i = 0; i < m; ++ i) {
			scanf("%d", &s);
			S.push(s);
		}

		while (!A.empty() && !S.empty()) {
			int a = A.top(); A.pop();
			int s = S.top(); S.pop();
			if (a <= s) {
				ans += a;
			} else if (a > s) {
				ans += s;
				A.push(a - s);
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}