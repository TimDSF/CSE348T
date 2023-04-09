#include <cstdio>
using namespace std;

int t;
int n;

int main() {
	scanf("%d", &t);
	while (t --) {
		int a, even = 0, odd = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a);
			if (a % 2 == 0) even += a;
			else odd += a;
		}
		if (even > odd) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}