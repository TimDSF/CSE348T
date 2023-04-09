#include <cstdio>
#include <string>
#include <climits>
#include <iostream>
#define N 300005
#define C0 (long long) 1000000000000
#define C1 (long long) 1000000000001
using namespace std;
int t;
long long c0[N], c1[N];
int main() {
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		s = ' ' + s + ' ';
		long long ans = LLONG_MAX;

		c0[0] = 0;
		for (int i = 1; i <= n + 1; ++ i) {
			c0[i] = c0[i - 1] + (s[i] == '0' ? 0 : 1);
		}

		c1[n + 1] = 0;
		for (int i = n; i >= 0; -- i) {
			c1[i] = c1[i + 1] + (s[i] == '1' ? 0 : 1);
		}

		for (int i = 1; i <= n + 1; ++ i) {
			ans = min(ans, (c0[i - 1] + c1[i]) * C1);
		}

		for (int i = 2; i <= n; ++ i) {
			if (s[i - 1] == '1' && s[i] == '0') {
				ans = min(ans, (c0[i - 2] + c1[i + 1]) * C1 + C0);
			}
		}

		printf("%lld\n", ans);
	}
	return 0;
}