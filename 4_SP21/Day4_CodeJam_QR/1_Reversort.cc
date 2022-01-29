#include <cstdio>
#include <algorithm>
using namespace std;
int T,n,a[105];
int main(){
	int t,i,j,k,p,q,cst,mn;
	scanf("%d",&T);
	for (t=0;t<T;++t){
		scanf("%d",&n);
		for (i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		cst = 0;
		for (i=0;i<n-1;++i){
			mn=0x7fffffff;
			for (k=i;k<n;++k){
				if (a[k]<mn){
					mn=a[k];
					j=k;
				}
			}
			cst += j-i+1;
			for (p=i,q=j;p<q;++p,--q){
				swap(a[p],a[q]);
			}
		}
		printf("Case #%d: %d\n",t+1,cst);
	}
	return 0;
}