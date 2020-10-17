#include <cstdio>
using namespace std;
int n,m,a[100001],s[400001]; 
// [ , ) intervals 
// a: starts from 0
// s: start from 1

void build(int l,int r,int i){
	if (l+1==r){
		s[i]=a[i];
		printf("[%d,%d) @ %d = %d\n",l,r,i,s[i]);
		return;
	}
	int m=(l+r)/2;
	build(l,m,i*2);
	build(m,r,i*2+1);
	s[i]=s[i*2]+s[i*2+1];
	printf("[%d,%d) @ %d = %d\n",l,r,i,s[i]);
}

int main(){
	int i,j;
	scanf("%d",&n);
	for (i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	build(0,n,1);

	return 0;
}