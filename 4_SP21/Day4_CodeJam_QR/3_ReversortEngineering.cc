#include <cstdio>
#include <algorithm>
using namespace std;
int T,n,a[105];
int main(){
	int t,i,j,k,cst;
	bool h;
	scanf("%d",&T);
	for (t=0;t<T;++t){
		scanf("%d%d",&n,&cst);
		i=0;j=n-1;h=1;
		cst -= n-1;
		if (cst<0){
			printf("Case #%d: IMPOSSIBLE\n",t+1);
			continue;
		}
		for (k=1;k<=n;++k){
			if (cst < n-k){
				if (h) a[i++]=k; else a[j--]=k;
			}else{
				cst -= n-k;
				h=!h;
				if (h) a[i++]=k; else a[j--]=k;
			}
		}
		if (cst!=0){
			printf("Case #%d: IMPOSSIBLE\n",t+1);
			continue;
		}
		printf("Case #%d:",t+1);
		for (i=0;i<n;++i){
			printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}