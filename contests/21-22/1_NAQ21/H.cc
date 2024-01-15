#include <cstdio>
using namespace std;

int n, a = -1; 

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; ++ i){
		if (a == -1){
			scanf("%d", &a);
		}else{
			int tmp;
			scanf("%d", &tmp);
			if (tmp % a == 0){
				printf("%d\n", tmp);
				a = -1;
			}
		}
	}

	return 0;
}