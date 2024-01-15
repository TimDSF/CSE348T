#include <algorithm>
#include <cstdio>
using namespace std;

int a[100005], n, mn, mx;

int main(){
	double ans, len;
	double mn2, mx2;

	scanf("%d%d%d", &n, &mn, &mx);
	mn2 = ((double) mn) / 2;
	mx2 = ((double) mx) / 2;

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 1; i < n; ++ i) {
		if (a[i] - a[i - 1] < mn) {
			printf("-1\n");
			return 0;
		}
	}

	ans = mx;
	len = ((double) a[0]) + mx2;

	for (int i = 1; i < n; ++ i) {
		double le = ((double) a[i]) - mn2; 
		if (le < len) {
			ans = ans - (len - le) * 2 + mn;
			len = a[i] + mn2;
		} else {
			double dis = min(((double)a[i]) - len, mx2);
			ans += dis * 2;
			len = a[i] + dis;
		}
	}

	printf("%lld\n", (long long) ans);
	return 0;
}