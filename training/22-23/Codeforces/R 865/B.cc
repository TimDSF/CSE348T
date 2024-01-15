#include <cstdio>
#include <queue>
#define N 100005
using namespace std;

int a[2][N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		queue<int> q0, q1;
		for (int i = 1; i <= n; ++ i) {
			q0.push(n + 1 - i);
			q1.push(n * 2 + 1 - i);
		}
		a[0][0] = q1.front(); q1.pop();
		a[1][n - 1] = q1.front(); q1.pop();

		for (int j = 1; j < n; ++ j) {
			if (j % 2 == 0) {
				a[0][j] = q1.front(); q1.pop();
				a[1][j - 1] = q1.front(); q1.pop();
			} else {
				a[0][j] = q0.front(); q0.pop();
				a[1][j - 1] = q0.front(); q0.pop();
			}
		}

		for (int i = 0; i < 2; ++ i) {
			for (int j = 0; j < n; ++ j) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}