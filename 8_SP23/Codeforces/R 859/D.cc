#include <cstdio>
#define N 200005
using namespace std;

int t;
int n, q;
long long a[N], p[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &q);
		p[0] = 0;
		for (int i = 1; i <= n; ++ i) {
			scanf("%lld", &a[i]);
			p[i] = p[i - 1] + a[i];
		}
		for (int i = 0; i < q; ++ i) {
			int l, r;
			long long k;
			scanf("%d%d%lld", &l, &r, &k);
			long long sum = p[n] - (p[r] - p[l - 1]) + (r - l + 1) * k;
			if (sum % 2) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}