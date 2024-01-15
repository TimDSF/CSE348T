#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T, a[4], tmp;

	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		a[0] = 0x7fffffff; a[1] = 0x7fffffff; a[2] = 0x7fffffff; a[3] = 0x7fffffff;
		
		for (int i = 0; i < 3; ++ i){
			for (int j = 0; j < 4; ++ j){
				scanf("%d", &tmp);
				a[j] = min(a[j], tmp);
			}
		}
		tmp = 1000000;

		printf("Case #%d:", t);
		if (a[0] + a[1] + a[2] + a[3] < tmp){
			printf(" IMPOSSIBLE\n");
		}else{
			for (int i = 0 ; i < 4; ++ i){
				if (a[i] < tmp){
					printf(" %d", a[i]);
					tmp -= a[i];
				}else{
					printf(" %d", tmp);
					tmp = 0;
				}
			}
			printf("\n");
		}
	}

	return 0;
}