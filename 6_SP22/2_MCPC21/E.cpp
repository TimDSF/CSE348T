#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n, i, bal = 0, min_b = 0, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &tmp);
		bal += tmp;
		min_b = min(min_b, bal);
	}
	printf("%d\n", - min_b);
	return 0;
}
