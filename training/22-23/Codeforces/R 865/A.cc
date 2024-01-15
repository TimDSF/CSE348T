#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("2\n%d %d\n%d %d\n", x - 1, 1, x, y);
	}
	return 0;
}