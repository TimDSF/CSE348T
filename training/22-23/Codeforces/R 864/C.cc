#include <algorithm>
#include <cstdio>
using namespace std;

int a[N][N], b[N][N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, d1, d, x = 1, y = 1;
		scanf("%d%d", &n, &m);
		
		printf("? 1 1\n"); fflush(stdout);
		scanf("%d", &d1);
		if (d1 == 0) {
			printf("! 1 1\n"); fflush(stdout);
			continue;
		}

		x = min(1 + d1, n);
		y = min(1 + d1, m);
		printf("? %d %d\n", x, y); fflush(stdout);
		scanf("%d", &d);
		if (d == 0) {
			printf("! %d %d\n", x, y); fflush(stdout);
			continue;
		}

		if (x != 1 + d1) {
			printf("! %d %d\n", x - d, y); fflush(stdout);
			continue;
		} else if (y != 1 + d1) {
			printf("! %d %d\n", x, y - d); fflush(stdout);
			continue;
		}

		x -= d;
		printf("? %d %d\n", x, y); fflush(stdout);
		scanf("%d", &d);
		if (d == 0) {
			printf("! %d %d\n", x, y); fflush(stdout);
		} else {
			printf("! %d %d\n", y, x); fflush(stdout);
		}
	}
	return 0;
}