#include <cstdio>
#include <algorithm>
#define N 200005
using namespace std;

int t;
int n;
long long a[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%lld", &a[i]);
		}
		sort(a, a + n);
		if (a[0] != 1) {
			printf("No\n");
			continue;
		}

		long long sum = 1;
		bool okay = true;
		for (int i = 1; i < n; ++ i) {
			if (a[i] <= sum) {
				sum += a[i];
			} else {
				okay = false;
				break;
			}
		}
		if (okay) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}