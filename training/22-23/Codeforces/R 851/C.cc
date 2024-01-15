#include <algorithm>
#include <cstdio>
using namespace std;

int n, N;

void solve() {
	scanf("%d", &n);

	if (n % 2 == 0) {
		printf("No\n");
		return;
	}

	printf("Yes\n");

	N = n * 2;

	for (int i = 1; i <= n / 2; ++ i) {
		printf("%d %d\n", i, N - n / 2 + i);
	}
	for (int i = n / 2 + 1; i <= n; ++ i) {
		printf("%d %d\n", i, n + i - n / 2);
	}
	return;
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}