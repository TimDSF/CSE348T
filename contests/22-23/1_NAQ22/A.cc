#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[500005];

int main(){
	int ans = 1;
	long long att = 0, def = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
	}

	if (n < 3) {
		printf("1\n");
		return 0;
	}

	sort(a, a + n);
	ans = n - 1;
	att = a[n - 1];

	for (int i = n - 2; i >= 0; -- i) {
		def += (long long) a[i];
		if (def >= att) {
			ans = i;
			att += def;
			def = 0;
		}
	}


	printf("%d\n", n - ans);

	return 0;
}