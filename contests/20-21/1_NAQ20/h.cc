#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,m,w,a[105][105];
int f[105][105][55];
string code;

int main(){
	int i,j,k,c,ans;
	string line;

	scanf("%d%d",&m,&n);
	cin >> code;
	w=code.length();

	for (i=n;i>0;--i){
		cin >> line;
		for (j=0;j<line.length();++j){
			a[i][j+1] = line[j] - 48;
		}
	}

	memset(f,0x3f,sizeof(f));

	f[1][1][0]=a[1][1];

	for (i=1;i<=n;++i){
		for (j=1;j<=m;++j){
			if (i > 1) f[i][j][0] = min(f[i][j][0],f[i-1][j][0]+a[i][j]);
			if (j > 1) f[i][j][0] = min(f[i][j][0],f[i][j-1][0]+a[i][j]);
		}
	}

	for (k=1;k<=w;++k){
		c = code[k-1] - 48;

		for (i=1;i<=n;++i){
			for (j=1;j<=m;++j){
				if (i > 1) f[i][j][k] = min(f[i][j][k],f[i-1][j][k]+a[i][j]);
				if (j > 1) f[i][j][k] = min(f[i][j][k],f[i][j-1][k]+a[i][j]);

				if (i > c+1) f[i][j][k] = min(f[i][j][k],f[i-c-1][j][k-1]+a[i][j]);
				if (j > c+1) f[i][j][k] = min(f[i][j][k],f[i][j-c-1][k-1]+a[i][j]);
			}
		}
	}

	ans = 0x7fffffff;
	for (k=0;k<=w;++k){
		ans = min(ans, f[n][m][k]);
	}
	printf("%d\n",ans);

	return 0;
}