#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
double p[105],f[105][105];
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

    f[1][0]=1-p[1];
    f[1][1]=p[1];
    max=f[1][1];

    for (i=2;i<=n;i++){
        tmp=0;
        f[i][0]=f[i-1][0]*(1-p[i]);

        for (j=1;j<=i;j++){
            f[i][j]=f[i-1][j-1]*p[i]+f[i-1][j]*(1-p[i]);
            tmp += f[i][j] * pow(j,(double)j/i);
        }

        if (tmp>max) max=tmp;
    }

    cout<<setprecision(10)<<max<<"\n";
    return 0;
}