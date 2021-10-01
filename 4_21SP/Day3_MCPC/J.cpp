// Credit: Tim Dong
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,c,a[1005],f[100005],sum;

int main(){
	int i,j;
	scanf("%d%d",&n,&c);
	for (i=0;i<n;++i){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	
	sort(a,a+n);
	memset(f,0xff,sizeof(f));
	
	f[0] = a[0];
	f[a[0]] = 0; // the largest of the smallest unused value of achieving weight i if f[i]

	for (i=1;i<n;++i){
		for (j=c;j>=0;--j){
			if (f[j] == 0) f[j] = a[i];
			if (j>=a[i] && f[j-a[i]] != -1) f[j] = max(f[j],f[j-a[i]]);
		}
	}

	for (i=1;i<=c;++i){
		if (f[i]+i>c){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%d\n",sum);
	return 0;
}