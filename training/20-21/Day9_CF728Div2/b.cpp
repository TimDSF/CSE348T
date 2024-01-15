#include <cstdio>
using namespace std;
int t, n, a[200005];
int main(){
	int ans;
	scanf("%d",&t);
	
	while(t--){
		ans = 0;
		
		scanf("%d",&n);
		for (int i=1; i<=n; ++i){
			scanf("%d",&a[i]);
		}
 
		for (int i=1; i<n; ++i){
			int j = a[i]-i;
			while(j <= i && j <=n) j += a[i];
			for (; j<=n; j+=a[i]){
				if ((long long)a[i] * a[j] == i + j) ++ ans;
			}
		}
 
		printf("%d\n", ans);
	}
	return 0;
}