#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string pi = "314159265358979323846264338327950288419716939937510";

void solve() {
	string ans;
	cin >> ans;
	for (int i = 0; i < ans.length(); ++ i) {
		if (pi[i] != ans[i]) {
			printf("%d\n", i);
			return;
		}
	}
	printf("%d\n", ans.length());
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}