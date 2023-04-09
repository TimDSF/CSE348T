#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, x1, y1, x2, y2;
		int a1 = 4, a2 = 4;
		scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
		if (x1 == 1) -- a1;
		if (x1 == n) -- a1;
		if (y1 == 1) -- a1;
		if (y1 == m) -- a1;

		if (x2 == 1) -- a2;
		if (x2 == n) -- a2;
		if (y2 == 1) -- a2;
		if (y2 == m) -- a2;

		printf("%d\n", min(a1, a2));
	}
	return 0;
}