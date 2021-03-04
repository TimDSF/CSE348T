#include <cstdio>
#define max_(a,b) a>b?a:b
using namespace std;

int n,m,f[100001][20],log[100001];
// f[i][j] = max ~ [ i , i + 2^j )

void logs(){
	log[1]=0;
	for (int i=2;i<=n;++i) log[i]=log[i/2]+1;
}

void calc(){
	int i,j;
	for (j=1;j<=log[n];++j){
		for (i=1;i+(1<<j)-1<=n;++i){ // 1<<j = 2^j
			f[i][j]=max_( f[i][j-1] , f[ i + ( 1<<(j-1) ) ][j-1] );
		}
	}
}

int max(int i,int j){ // max ~ [i,j]
	int l=log[j-i+1];
	return max_( f[i][l] , f[j-(1<<l)+1][l] );
}

int main(){
	int i,j,k;

	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&f[i][0]);
	}

	logs();
	calc();

	scanf("%d",&m);
	for (i=0;i<m;++i){
		scanf("%d%d",&j,&k);
		printf("%d\n",max(j,k));
	}
}