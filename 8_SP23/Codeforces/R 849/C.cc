#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void solve() {
	int n, ans;
	string s;

	scanf("%d", &n);
	cin >> s;

	ans = n;
	for (int i = 0, j = n - 1; i < j; ++ i, -- j) {
		if (s[i] == '1' && s[j] == '0' || s[i] == '0' && s[j] == '1') {
			ans -= 2;
		} else {
			break;
		}
	}

	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}