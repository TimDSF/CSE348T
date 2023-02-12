#include <cstdio>
#include <map>
using namespace std;

void solve() {
	int x, a = -1, b = 0;
	bool prev_0 = false;
	scanf("%d", &x);

	for (int i = 1; i <= x; i <<= 1) {
		if (i & x) {
			if (!prev_0) {
				printf("-1\n");
				return;
			}
			prev_0 = false;
			if (a == -1) {
				a = i;
			} else {
				b |= i;
			}
		} else {
			prev_0 = true;
		}
	}

	printf("%d %d\n", a + (x >> 1), b + (x >> 1));
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}