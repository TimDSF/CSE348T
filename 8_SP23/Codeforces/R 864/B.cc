#include <cstdio>
#define N 1005
using namespace std;

int a[N][N], b[N][N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k, d = 0;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				scanf("%d", &a[i][j]);
				b[n - i - 1][n - j - 1] = a[i][j];
			}
		}

		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				if (a[i][j] != b[i][j]) ++ d;
			}
		}

		d /= 2;
		if (d <= k && ((k - d) % 2 == 0 || n % 2 == 1)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}