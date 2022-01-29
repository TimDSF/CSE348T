#include <cstdio>
using namespace std;
int t, n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if (n % 2 == 0){
			for (int i=1; i<=n; ++i){
				printf("%d ", i % 2 ? i + 1: i - 1);
			}
		}else{
			printf("3 1 2 ");
			for (int i=4; i<=n; ++i){
				printf("%d ", i % 2 ? i - 1: i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}