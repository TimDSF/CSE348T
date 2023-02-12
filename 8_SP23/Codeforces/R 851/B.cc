#include <cstdio>
using namespace std;

int a[1005], idx[1005];

void solve() {
	int n, x = 0, y = 0, bit = 1, dif = 0;
	scanf("%d", &n);
	
	while (n != 0) {
		int r = n % 10, xb = r / 2, yb = r / 2;
		n /= 10;

		if (r % 2 != 0) {
			if (dif == 1) {
				++ yb;
			} else {
				++ xb;
			}
			dif += (xb - yb);
		}

		x += bit * xb;
		y += bit * yb;
		bit *= 10;
	}

	printf("%d %d\n", x, y);
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}