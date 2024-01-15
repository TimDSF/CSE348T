// Credit: Tim Dong
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 300005
#define lowbit(x) x&(-x)
using namespace std;

int n,a[N],b[N],bit[N];
long long f1[N],f2[N],ans;
unordered_map<int,int> mp;

void update(int i,int d){
	while(i<=n){
		bit[i]+=d;
		i+=lowbit(i);
	}
}
int sum(int i){
	int ans=0;
	while(i>0){
		ans+=bit[i];
		i-=lowbit(i);
	}
	return ans;
}

int main(){
	int i,j;

	scanf("%d",&n);
	for (i=0;i<n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}

	sort(b,b+n);
	for (i=0;i<n;++i){
		mp[b[i]]=i+1;
	}
	for (i=0;i<n;++i){
		a[i]=mp[a[i]];
	}
	
	f1[0]=0;
	update(a[0],1);
	for (i=1;i<n;++i){
		f1[i] = f1[i-1] + (long long) (i-sum(a[i]));
		update(a[i],1);
	}

	memset(bit,0,sizeof(bit));

	f2[n-1]=0;
	update(a[n-1],1);
	for (i=n-2;i>=0;--i){
		f2[i] = f2[i+1] + (long long) (n-i-1-sum(a[i]));
		update(a[i],1);
	}

	ans = min(f1[n-1],f2[0]);
	for (i=0;i<n-1;++i){
		ans = min(ans,f1[i]+f2[i+1]);
	}

	printf("%lld\n",ans);
	return 0;
}