#include <cstdio>
#include <queue>
#define N 300005
using namespace std;

long long a[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i < n - 1; ++ i) {
			if (a[i - 1] > a[i]) {
				long long d = a[i - 1] - a[i];
				a[i] += d;
				a[i + 1] += d;

			}
		}
		for (int i = n - 2; i > 0; -- i) {
			if (a[i] > a[i + 1]) {
				long long d = a[i] - a[i + 1];
				a[i] -= d;
				a[i - 1] -= d;

			}
		}
		// for (int i = 0; i < n; ++ i) printf("%d ", a[i]); printf("\n");
		if (a[0] <= a[1]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}