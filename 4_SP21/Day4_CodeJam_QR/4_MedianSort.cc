#include <cstdio>
#include <iostream>
using namespace std;
int T,n,Q,a[55];
int test(int a,int b,int c){
	int r;
	// printf("%d %d %d\n",a,b,c);
	// fflush(stdout);
	cout << a << ' ' << b << ' ' << c << endl;
	// scanf("%d",&r);
	cin >> r;
	return r;
}
int submit(){
	int i;
	for (i=1;i<=n;++i){
		// printf("%d ",a[i]);
		cout << a[i] << ' ';
	}
	cout << endl;
	// printf("\n");
	// fflush(stdout);
	// scanf("%d",&i);
	cin >> i;
	return i;
}
int main(){
	int i,j,l,r,res,m1,m2;
	// scanf("%d%d%d",&T,&n,&Q);
	cin >> T >> n >> Q;
	while(T--){
		res=test(1,2,3);
		a[1]=(res+1)%3+1;a[2]=res;a[3]=res%3+1;
		// for (int i=1;i<=n;++i){
		// 	printf("%d ",a[i]);
		// }printf("\n");
		
		for (i=4;i<=n;++i){
			l=1;r=i-1;
			while(l<r){
				m1=l+(r-l)/3;
				m2=r-(r-l)/3;
				// printf("(%d,%d,%d,%d)\n",l,m1,m2,r);
				res=test(a[m1],a[m2],i);
				if (res==-1) return 0;
				if (res==i){
					l=m1+1;r=m2-1;
				}else if (res==a[m1]){
					r=m1-1;
				}else/* if (r==a[m2])*/{
					l=m2+1;
				}
			}
			// printf("(%d,%d,%d,%d)\n",l,m1,m2,r);
			if (l==r){
				if (l!=1){
					res=test(a[l-1],a[l],i);
					if (res==a[l]) ++l;
				}else{
					res=test(a[l],a[l+1],i);
					if (res==i) ++l;
				}
			}
			for (j=i;j>l;--j){
				a[j]=a[j-1];
			}
			a[l]=i;
			// for (int i=1;i<=n;++i){
			// 	printf("%d ",a[i]);
			// }printf("\n");
		}

		if (submit()==1) continue; else return 0;
	}
}