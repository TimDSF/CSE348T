// Copyright @ Tim Dong 2019

#include <bits/stdc++.h>
using namespace std;
int n,k;
long long t[20005];
int main(){
    int i;
    long long l,r,m,tmp,total;
    scanf("%d%d",&n,&k);
    if (k>n) k=n;
    for (i=0;i<n;i++){
        scanf("%lld",&t[i]);
    }
    sort(t,t+n);
    //  using the 0 to k-1 drivers
    l=t[0];
    r=2*t[k-1]*((n+3)/4);
    while(l<r){
        m=(l+r)/2;
        total=0;
        for (i=0;i<k;i++){
            tmp=(m/t[i]+1)/2;
            total+=tmp*4;
            if (m>=t[i]) total++;
        }
        if (total<n){
            l=m+1;
        }else{
            r=m;
        }
    }
    printf("%lld\n",l);
    return 0;
}
