#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

long long pow(int a, int b) {
	if (b == 0) return 1; 
	if (b == 1) return a;
 	long long tmp = pow(a, b / 2);
 	tmp *= tmp;
 	if (b % 2) tmp *= a;
 	return tmp;
}

void solve() {
	long long n; scanf("%lld", &n);
	for (int k = 2; k * k <= n; ++ k) {
		int l = 2, r = ceil(log(n) / log(k));
		while (l < r) {
			int m = (l + r) / 2;
			long long s = (pow(k, m + 1) - 1) / (k - 1);
			if (s == n) {
				printf("YES\n");
				return;
			} else if (s < n) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
	}
	printf("NO\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}
