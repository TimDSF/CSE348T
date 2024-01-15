#include <cstdio>
#define lowbit(x) x&(-x)

using namespace std;
int n,m,a[100001],bit[100001];

// index starts from 1
// n numbers, m queries
// [u,v] closed-open intervals

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
	int i,u;

	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&a[i]);
		update(i,a[i]);
	}
	
	scanf("%d",&m);
	for (i=0;i<m;++i){
		scanf("%d",&u);
		printf("%d\n",sum(u));
	}

	return 0;
}