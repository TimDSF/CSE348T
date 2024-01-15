#include <math.h>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define pi 3.141592653589793238462643383279502884L
using namespace std;

int n,x[10005],y[10005],r[10005],b,d;
double dis(int x,int y){
	return sqrt((double)x*x+y*y);
}
double angle(int x,int y){
	if (x==0 && y>0) return pi/2;
	if (x==0 && y<0) return pi/2*3;
	double a = atan((double)y/x);
	if (x<0) a += pi;
	if (x>0 && y<0) a += pi*2;
	return a;
}
int main(){
	int i,m=0,le=0;
	pair<double,bool> p[40005]; // < argument, start = 0 | end = 1>
	double ans=0;

	scanf("%d",&n);
	for (i=0;i<n;++i) scanf("%d%d%d",&x[i],&y[i],&r[i]);
	scanf("%d%d",&b,&d);
	
	for (i=0;i<n;++i) r[i]+=b;
	b=0;

	for (i=0;i<n;++i){
		double di = dis(x[i],y[i]);
		double ar = angle(x[i],y[i]),sp;
		if (di < (double)d + r[i]){
			if ((double)d*d >= di*di - r[i]*r[i]){
				sp = asin((double)r[i]/di);
			}else{
				sp = acos((double)(d*d+di*di-r[i]*r[i])/(2*d*di));
			}
			if (ar<sp){
				p[m++]=make_pair(ar-sp+pi*2,false);
				p[m++]=make_pair(pi*2,true);
				p[m++]=make_pair(0,false);
				p[m++]=make_pair(ar+sp,true);
			}else if (ar+sp>pi*2){
				p[m++]=make_pair(ar-sp,false);
				p[m++]=make_pair(pi*2,true);
				p[m++]=make_pair(0,false);
				p[m++]=make_pair(ar+sp-pi*2,true);
			}else{
				p[m++]=make_pair(ar-sp,false);
				p[m++]=make_pair(ar+sp,true);
			}
		}
	}
	if (m==0){
		printf("1.000000\n");
		return 0;
	}
	sort(p,p+m);
	p[m].first = 2*pi;
	// cout<<'\n';
	ans += p[0].first;
	
	for (i=0;i<m;++i){
		// cout<<p[i].first<<' '<<p[i].second<<'\n';
		le += p[i].second?-1:1;
		if (le == 0) ans += p[i+1].first-p[i].first;
		// cout<<"  "<<i<<' '<<le<<' '<<ans<<'\n';
	}
	ans /= pi*2;
	cout << setprecision(8) << ans << "\n";
	return 0;
}