// Credit: Tim Dong
#include <cstdio>
#include <iostream>
using namespace std;

int n,m;

int main(){
	int i,sum=0,s;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;++i){
		scanf("%d",&s);
		sum += s;
	}
	cout << (double)(sum - (n-m)*3) / n << " " << (double)(sum + (n-m)*3) / n << "\n";
	return 0;
}