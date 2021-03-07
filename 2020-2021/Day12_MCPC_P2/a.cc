#include <cstdio>
using namespace std;

int a[5][5],b[5][5],d;

int main(){
	int i,j,k,pre;
	for (i=0;i<4;++i){
		for (j=0;j<4;++j){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&d);

	if (d==0){
		for (i=0;i<4;++i){
			k=0;pre=-1;
			for (j=0;j<4;++j){
				if (a[i][j]==0) continue;	
				b[i][k] = a[i][j];
				++k;
				if (a[i][j]==pre){
					--k;
					b[i][k]=0;
					b[i][k-1]*=2;
					pre = -1;
				}else{
					pre = a[i][j];
				}
			}
		}
	}else if (d==1){
		for (j=0;j<4;++j){
			k=0;pre=-1;
			for (i=0;i<4;++i){
				if (a[i][j]==0) continue;	
				b[k][j] = a[i][j];
				++k;
				if (a[i][j]==pre){
					--k;
					b[k][j]=0;
					b[k-1][j]*=2;
					pre = -1;
				}else{
					pre = a[i][j];
				}
			}
		}
	}else if (d==2){
		for (i=0;i<4;++i){
			k=3;pre=-1;
			for (j=3;j>=0;--j){
				if (a[i][j]==0) continue;	
				b[i][k] = a[i][j];
				--k;
				if (a[i][j]==pre){
					++k;
					b[i][k]=0;
					b[i][k+1]*=2;
					pre = -1;
				}else{
					pre = a[i][j];
				}
			}
		}
	}else if (d==3){
		for (j=0;j<4;++j){
			k=3;pre=-1;
			for (i=3;i>=0;--i){
				if (a[i][j]==0) continue;	
				b[k][j] = a[i][j];
				--k;
				if (a[i][j]==pre){
					++k;
					b[k][j]=0;
					b[k+1][j]*=2;
					pre = -1;
				}else{
					pre = a[i][j];
				}
			}
		}
	}

	for (i=0;i<4;++i){
		for (j=0;j<4;++j){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}