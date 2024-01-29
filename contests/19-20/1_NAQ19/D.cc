#include <cstdio>
using namespace std;
int n,a[205];
int main(){
	int i,j;
	bool b=1;
	scanf("%d",&n);
	n++;
	a[0]=0;
	for (i=1;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<n-1;i++){
		for (j=a[i]+1;j<a[i+1];j++){
			printf("%d\n",j);
			b=0;
		}
	}
	if (b) printf("good job\n");
	return 0;
}