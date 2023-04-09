#include <cmath>
#include <cstdio>
using namespace std;
int t;
int a[35];
int main() {
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);

		if (k == n * (n + 1) / 2) {
			for (int i = 0; i < n; ++ i) {
				printf("1 ");
			}
			printf("\n");
			continue;
		}

		int cur = 0, ck = 0, s0 = -1;
		a[0] = -1000;
		for (int i = 1; i < n; ++ i) {
			if (ck + (cur + 1) * (cur + 2) / 2 > k) {
				a[i] = -1000;
				ck += cur * (cur + 1) / 2;
				if (s0 == -1) s0 = cur;
				cur = 0;
			} else {
				a[i] = 2;
				++ cur;
			}
		}

		ck += cur * (cur + 1) / 2;
		if (s0 == -1) s0 = cur;
		int r = k - ck;
		a[0] =  - 2 * (s0 - r) - 1;

		for (int i = 0; i < n; ++ i) {
			printf("%d ", a[i]);
		}
		printf("\n");
/*
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; ++ i) {
			for (int j = i; j < n; ++ j) {
				int s = 0;
				for (int k = i; k <= j; ++ k) {
					s += a[k];
				}
				ans1 += s > 0;
				ans2 += s < 0;
			}
		}
		printf("=> %d %d\n", ans1, ans1 + ans2 - n * (n + 1) / 2);
*/
	}
	return 0;
}