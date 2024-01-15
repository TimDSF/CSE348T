#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;

	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		int n, a[1000005], ans = 0;;
		
		scanf("%d", &n);
		
		for (int i = 0; i < n; ++ i){
			scanf("%d", &a[i]);
		}
		sort(a, a+n);

		for (int i = 0; i < n; ++ i){
			ans += ans < a[i];
		}

		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}