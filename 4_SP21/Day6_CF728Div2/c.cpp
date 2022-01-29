#include <cstdio>
#include <algorithm>
using namespace std;
int t, n, a[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		long long ans = 0;

		scanf("%d",&n);
		for (int i=0; i<n; ++i){
			scanf("%d", &a[i]);
		}

		if (n < 3){
			printf("0\n");
			continue;
		}

		sort(a, a + n);

		for (int i=1; i<n; ++i){
			ans += (long long) a[i] * (n-2*i-1);
		}
		ans += a[n-1];

		printf("%lld\n", ans);
	}
	return 0;
}