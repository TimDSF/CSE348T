#include <cstdio>
using namespace std;

// a: array of numbers, [0,n)
// s: sum   over [l,r) at index i, index from 1.
int n,m,a[100001],s[400001],d[400001]; 

// initialize s[i] to sum of a[l,r)
void build(int l,int r,int i){
	if (l+1==r){
		s[i]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,i*2);
	build(m,r,i*2+1);
	s[i]=s[i*2]+s[i*2+1];
}

// calculate: sum of a[fm,to)
// current node: s[i] of sum [l,r)
int sum(int fm,int to,int l,int r,int i){
	if (fm<=l && r<=to) return s[i];
	int m=(l+r)/2,ans=0;
	if (fm<m) ans+=sum(fm,to,l,m,i*2);
	if (m<to) ans+=sum(fm,to,m,r,i*2+1);
	return ans;
}

int main(){
	int i,fm,to,dl;
	scanf("%d",&n);
	for (i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	build(0,n,1);

	scanf("%d",&m);
	for (i=0;i<m;++i){
		scanf("%d%d",&fm,&to); // input is [ , ]
		printf("%d\n",sum(fm,to+1,0,n,1));
	}

	return 0;
}