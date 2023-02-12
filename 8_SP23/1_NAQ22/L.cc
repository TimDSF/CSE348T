#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	long long c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main() {
	int t, s;
	long long T = 0, S = 0;

	scanf("%d%d", &t, &s);

	for (int i = 0; i <= s; ++ i) {
		int rt = t - i;

		int rs_l = s - i, rs_r = s * 2;

		while (rs_l < rs_r) {
			int j = (rs_l + rs_r + 1) / 2;
			int diag = min(i, j);
			double cost = 1.5 * diag + max(i, j) - diag;
			if (cost <= s) {
				rs_l = j;
			} else {
				rs_r = j - 1;
			}
		}

		int rs = rs_l;

		if (rt >= 0) {
			rt = min(rt, rs);

			T += (rt * 2 + 1) * (i != 0 ? 2 : 1);
			S += (rs * 2 + 1) * (i != 0 ? 2 : 1);
		} else {
			S += (rs * 2 + 1) * (i != 0 ? 2 : 1);
		}
	}

	long long G = gcd(T, S);

	if (G == S) {
		printf("%lld\n", T / G);
	} else {
		printf("%lld/%lld\n", T / G, S / G);
	}
}