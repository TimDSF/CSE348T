#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
double p[105],pp[105][105];
double max;
bool cmp(double a,double b){
	return a>b;
}
int main(){
	double tmp,max;
	int i,j,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&k);
		p[i]=k/100.0;
	}
	sort(p+1,p+n+1,cmp);
	pp[1][0]=1-p[1];
	pp[1][1]=p[1];
//	printf("%f %f\n",pp[1][0],pp[1][1]);
	max=pp[1][1];
//	printf("%f\n",max);
	for (i=2;i<=n;i++){
		tmp=0;
		pp[i][0]=pp[i-1][0]*(1-p[i]);
//		printf("%f ",pp[i][0]);
		for (j=1;j<=i;j++){
			pp[i][j]=pp[i-1][j-1]*p[i]+pp[i-1][j]*(1-p[i]);
//			printf("%f ",pp[i][j]);
			tmp+=pp[i][j]*pow(j,(double)j/i);
		}
//		printf("\n");
//		printf("%f\n",tmp);
		if (tmp>max) max=tmp;
	}
	cout<<setprecision(10)<<max<<"\n";
	return 0;
}