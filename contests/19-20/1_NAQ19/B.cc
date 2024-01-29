#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long m,n,mm,nn,c,tmp;
int main(){
	cin>>m>>n;
	mm=m;
	nn=n;
	if (n==m){
		cout<<n<<"\n";
		return 0;
	}
	if (m<n) swap(m,n);
	while(m%n){
		tmp=m%n;
		m=n;
		n=tmp;
	}
	c=n;
	m=mm/c;
	n=nn/c;
	if (n%2==1 && m%2==1) cout<<c<<"\n"; else printf("0\n");
	return 0;
}