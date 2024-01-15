#include <cstdio>
using namespace std;

int t;

int main() {
	scanf("%d", &t);
	while (t --) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a + b == c) printf("+\n");
		else printf("-\n");
	}
	return 0;
}