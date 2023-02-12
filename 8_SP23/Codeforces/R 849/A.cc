#include <cstdio>
#include <iostream>
using namespace std;

void solve() {
	char c;
	cin >> c;
	if (c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'f' || c == 'r' || c == 's') {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}