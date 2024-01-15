#include <cstdio>
using namespace std;

int T;
int main() {
	scanf("%d", &T);
	while (T--) {
		int original, res, found = 0, bitmask = 1, cur = 0, ans = 0;
		scanf("%d", &original);
		if (original == 0) {
			printf("! 0\n"); fflush(stdout);
		}

		while (original != found) {
			int diff = bitmask - cur;
			printf("- %d\n", diff); fflush(stdout);
			scanf("%d", &res);
			if (res < original) {
				++ found;
				ans += bitmask;
			} 
			bitmask <<= 1;
			cur += diff;
		}

		printf("! %d\n", ans); fflush(stdout);
	}

	return 0;
}