#include <string.h>
#include <cstdio>
using namespace std;

int a[1005], idx[1005];

void solve() {
	int n, cnt = 0;
	memset(idx, 0, sizeof(idx));
	scanf("%d", &n);

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		cnt += a[i] == 2;

		if (idx[cnt] == 0) {
			idx[cnt] = i;
		}
	}

	if (cnt % 2 == 0) {
		printf("%d\n", idx[cnt / 2]);
	} else {
		printf("-1\n");
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}