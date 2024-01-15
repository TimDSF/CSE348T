#include <cstdio>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

void solve() {
	int n, ans = 0, num_be = 0, num_af = 0;
	string s;
	unordered_map<char, int> be, af;

	scanf("%d", &n);
	cin >> s;

	for (const char c : s) {
		++ af[c];
		if (af[c] == 1) ++ num_af;
	}
	ans = num_af;

	for (const char c : s) {
		++ be[c];
		if (be[c] == 1) ++ num_be;

		-- af[c];
		if (af[c] == 0) -- num_af;

		ans = max(num_be + num_af, ans);
	}

	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}