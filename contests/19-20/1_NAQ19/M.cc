#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;
int n,g,h,r,w;
double minn,maxx;
int main(){
	scanf("%d",&n);
	while(n){
		n--;
		scanf("%d%d%d%d",&w,&g,&h,&r);
		g-=r;
		h-=r;
		minn=sqrt((double)pow(w,2)+pow(h-g,2));
		maxx=sqrt((double)pow(w,2)+pow(h+g,2));
		cout<<setprecision(16)<<minn<<" "<<setprecision(16)<<maxx<<"\n";
	}
	return 0;
}