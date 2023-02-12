#include <cstdio>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	if (n % 2) {
		printf("-1\n");
	} else {
		printf("%d 1\n", n / 2);
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}