#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string pi = "314159265358979323846264338327950288419716939937510";

void solve() {
	int n, s, r;
	scanf("%d%d%d", &n, &s, &r);
	printf("%d", s - r);
	int ave = r / (n - 1);
	int res = r % (n - 1);
	int i;

	for (i = 0; i < n - 1 - res; ++ i) {
		printf(" %d", ave);
	}
	for (; i < n - 1; ++ i) {
		printf(" %d", ave + 1);
	}
	printf("\n");
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}