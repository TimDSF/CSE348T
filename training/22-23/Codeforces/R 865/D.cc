#include <cstdio>
#define N 1003
using namespace std;

int a[N], ans1[N], ans2[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, d, max_d = 0, max_i = 0;
		scanf("%d", &n);

		a[1] = 1;
		for (int i = 2; i <= n; ++ i) {
			if (a[i - 1] > n / 2) {
				a[i] = n + 2 - a[i - 1];
			} else {
				a[i] = n + 1 - a[i - 1];
			}
		}
		
		printf("+ %d\n", n + 1); fflush(stdout);
		scanf("%d", &d);
		if (d == -2) return 0;
		printf("+ %d\n", n + 2); fflush(stdout);
		scanf("%d", &d);
		if (d == -2) return 0;

		for (int i = 2; i <= n; ++ i) {
			printf("? %d %d\n", 1, i); fflush(stdout);
			scanf("%d", &d);
			if (d == -1) return 0;
			if (d > max_d){ 
				max_d = d;
				max_i = i;
			}
		}

		ans1[max_i] = a[1];
		ans2[max_i] = a[n];
		for (int i = 1; i < n; ++ i) {
			int j = (i < max_i) ? i : i + 1;
			printf("? %d %d\n", max_i, j); fflush(stdout);
			scanf("%d", &d);
			if (d == -1) return 0;
			ans1[j] = a[d + 1];
			ans2[j] = a[n - d];
		}

		printf("! ");
		for (int i = 1; i <= n; ++ i) {
			printf("%d ", ans1[i]);
		}
		for (int i = 1; i <= n; ++ i) {
			printf("%d ", ans2[i]);
		}
		printf("\n");
		fflush(stdout);

		scanf("%d", &d);
		if (d == -2) return 0;
	}
	return 0;
}