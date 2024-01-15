#include <cstdio>
#define N 105
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int a;
		bool okay = false;
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a);
			if (a <= i) okay = true;
		}
		if (okay) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}