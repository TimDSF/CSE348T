#include <cstdio>
using namespace std;
int n,a[10];
long long ans;

long long solve2(int);

long long solve(int idx){
	int i, cnt1=0, cnt2=0, c3=a[idx+1]/10;
	
	if (idx < n-1){
		for (i=0; i<a[idx]; ++i){	
			cnt1 += (i%10) < c3;
			cnt2 += (i%10) == c3;
		}
		return cnt1 * solve(idx+1) + cnt2 * solve2(idx+1);

	}else{
		return a[idx];
	}
}
long long solve2(int idx){
	int i, cnt1=0, cnt2=0, c3=a[idx+1]/10;
	if (idx < n-1){
		for (i=a[idx]/10*10; i<a[idx]; ++i){	
			cnt1 += (i%10) < c3;
			cnt2 += (i%10) == c3;
		}
		return cnt1 * solve(idx+1) + cnt2 * solve2(idx+1);

	}else{
		return a[idx]%10;
	}
}

int main(){
	int i;
	long long pro=1;
	scanf("%d",&n);
	for (i=0;i<n;++i){
		scanf("%d",&a[i]);
		pro *= a[i];
	}

	printf("%lld\n",pro-solve(0));
}