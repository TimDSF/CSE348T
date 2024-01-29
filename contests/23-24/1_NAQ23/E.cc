#include <cstdio>
#include <algorithm>
#define N 55
using namespace std;

int n, a[N], b[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d%d", &a[i], &b[i]);

	int ans = 0, st = -1;

	for (int i = 1; i <= n - 2;) {
		int lo = max(st, a[i]);
		int hi = b[i];

		bool found = false;
		for (int j = lo; j <= hi - 2; ++ j) {
			if (j + 2 <= b[j] && a[j + 1] <= j && j + 2 <= b[j + 1] && a[j + 2] <= j) {
				++ ans;
				found = true;
				i = j + 3;
				st = i;
				// printf("%d~%d\n", j, j + 2);
				break;
			}
		}

		if (!found) ++ i;
	}

	printf("%d\n", ans);

	return 0;
}