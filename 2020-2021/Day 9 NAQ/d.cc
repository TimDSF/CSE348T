#include <cmath>
#include <cstdio>
using namespace std;

int w,n,a[105];
bool b[101];

int main(){
	int i,j;
	scanf("%d%d",&w,&n);

	a[0]=0;
	++n;
	for (i=1;i<n;++i){
		scanf("%d",&a[i]);
	}
	a[n]=w;
	++n;

	for (i=0;i<n;++i){
		for (j=i+1;j<n;++j){
			b[abs(a[i]-a[j])] = 1;
		}
	}

	for (i=0;i<101;++i){
		if (b[i]) printf("%d ",i);
	}
	printf("\n");

	return 0;
}