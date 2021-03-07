#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
int main(){
	cin >> n >> m;
	long long gcd,nn,mm;
	if (n < m) swap(n,m);
	nn = n;
	mm = m;
	gcd = m;
	while(n%m){
		gcd = n%m;
		n = m;
		m = gcd;
	}
	nn /= gcd;
	mm /= gcd;
	if (nn % 2 == 1 && mm % 2 == 1){
		printf("%lld\n",gcd);
	}else{
		printf("0\n");
	}
	return 0;
}