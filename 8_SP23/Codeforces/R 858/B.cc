#include <cstdio>
using namespace std;
 
int t, n;
int main(){
	scanf("%d", &t);
	while (t--) {
		int c0 = 0, c1 = 0, c2 = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			int a;
			scanf("%d", &a);
			if (a == 0) {
				++ c0;
			} else if (a == 1){
				++ c1;
			} else {
				++ c2;
			}
		}
		if (c0 <= c1 + c2 + 1) {
			printf("0\n");
		} else {
			if (c1 == 0 || c2 > 0) {
				printf("1\n");
			} else {
				printf("2\n");
			}
		}
	}
	return 0;
}
