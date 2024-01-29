#include <algorithm>
#include <cstdio>
#define N 55
using namespace std;

int n, r;

int a[N];

int main(){
	scanf("%d%d", &n, &r);

	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	sort(a, a + n);

	int total = 0, ans = 0, cap = r * 5;

	for (int i = 0; i < n; ++ i) {
		if (total + a[i] <= cap) {
			total += a[i];
			++ ans;
		} else {
			break;
		}
	}

	printf("%d\n", ans);

	return 0;
}