#include <cstdio>
using namespace std;

int t;
int n, a[200005], p[100005];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		p[0] = 0;
		for (int i = 1 ; i <= n; ++ i) {
			scanf("%d", &a[i]);
			p[i] = p[i - 1] + a[i];
		}

		int l = 1, r = n;
		while (l < r) {
			int m = (l + r) / 2, w;
			
			printf("? %d", m - l + 1);
			for (int i = l; i <= m; ++ i) printf(" %d", i);
			printf("\n"); fflush(stdout);

			scanf("%d", &w);
			if (w == p[m] - p[l - 1]) {
				l = m + 1;
			} else {
				r = m;
			}
		}

		printf("! %d\n", l); fflush(stdout);
	}
	return 0;
}