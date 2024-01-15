#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void solve() {
	int m, n;
	string s, l, r;
	cin >> s >> m >> l >> r;
	n = s.length();

	int st = 0;
	for (int i = 0; i < m; ++ i) {
		int rt = -1;
		for (int c = l[i]; c <= r[i]; ++ c) {
			bool found = false;
			for (int j = st; j < n; ++ j) {
				if (s[j] == c) {
					rt = max(rt, j);
					found = true;
					break;
				}
			}
			if (!found) {
				printf("YES\n");
				return;
			}
		}
		st = rt + 1;
	}
	printf("NO\n");
}
int main() {
	int t; scanf("%d", &t);
	while (t --) {
		solve();
	}
	return 0;
}