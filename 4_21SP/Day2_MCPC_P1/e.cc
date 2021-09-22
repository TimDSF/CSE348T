#include <cstdio>
#include <iostream>
#define lowbit(x) x&(-x)
using namespace std;

int n,a[100005],bitF[100005],bitB[100005];
long long ans = 0;

void update(int i,int d,int bit[]){
	while(i<=n){
		bit[i]+=d;
		i+=lowbit(i);
	}
}
int sum(int i,int bit[]){
	int ans=0;
	while(i>0){
		ans+=bit[i];
		i-=lowbit(i);
	}
	return ans;
}

int main(){
	int i;

	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&a[i]);
		update(a[i],1,bitB);
	}

	update(a[1],-1,bitB);
	update(a[1],1,bitF);

	for (i=2;i<n;++i){
		update(a[i],-1,bitB);
		update(a[i],1,bitF);

		ans += (long long)(i-sum(a[i],bitF)) * sum(a[i]-1,bitB);
	}

	printf("%lld\n",ans);

	return 0;
}