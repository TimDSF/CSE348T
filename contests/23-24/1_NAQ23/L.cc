#include <cstdio>
using namespace std;

int n, a, b;
int main() {
	scanf("%d%d%d", &n, &a, &b);

	bool aa = false, bb = false;
	for (int i = 1; i < n; ++ i) {
		int x; scanf("%d", &x);
		aa |= x == a;
		bb |= x == b;
	}


	if (aa && bb) {
		for (int x = a; x <= b; ++ x) {
			printf("%d\n", x);
		}
	} else if (!aa && bb) {
		printf("%d\n", a);
	} else if (aa && !bb) {
		printf("%d\n", b);
	} else {
		printf("-1\n");
	}

	return 0;
}