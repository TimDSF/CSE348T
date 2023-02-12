#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void solve() {
	int n;
	int x = 0, y = 0;
	string s;

	scanf("%d", &n);
	cin >> s;

	for (const char c : s) {
		if (c == 'L') {
			-- x;
		} else if (c == 'R') {
			++ x;
		} else if (c == 'U') {
			++ y;
		} else if (c == 'D') {
			-- y;
		}

		if (x == 1 && y == 1) {
			printf("Yes\n");
			return;
		}
	}

	printf("No\n");
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}