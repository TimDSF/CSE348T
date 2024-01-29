#include <cstdio>
using namespace std;
int n,a[1000005];
int main(){
	int i;
	long long sum=0;
	double max;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if ((double)sum/i>max) max=(double)sum/i;
	}
	sum=0;
	for (i=n;i>0;i--){
		sum+=a[i];
		if ((double)sum/(n-i+1)>max) max=(double)sum/(n-i+1);
	}
	printf("%.7f\n",max);
	return 0;
}