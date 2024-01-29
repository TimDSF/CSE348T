#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,A[1005],B[1005],V;
int main(){
	int i,a,b,d,wa=0,wb=0;
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++){
		scanf("%d%d%d",&d,&a,&b);
		A[d]+=a;
		B[d]+=b;
		V+=a+b;
	}
	for (i=1;i<=m;i++){
		printf("%c ",A[i]>B[i]?'A':'B');
		if (A[i]<B[i]){
			d=A[i];
		}else{
			d=A[i]-(A[i]+B[i])/2-1;
			d=d>0?d:0;
		}
		printf("%d ",d);
		wa+=d;
		if (A[i]>B[i]){
			d=B[i];
		}else{
			d=B[i]-(A[i]+B[i])/2-1;
			d=d>0?d:0;
		}
		printf("%d\n",d);
		wb+=d;
	}
	cout<<setprecision(8)<<(double)abs(wa-wb)/V;
	return 0;
}