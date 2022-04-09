#include <cstdio>
using namespace std;

int n, m, a[101], c[101], sum = 0;

int main(){
	scanf("%d%d", &n, &m);
	int i = 0;

	for (i = 0; i < m; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	i = 0;
	while ((n --) && sum){
		if (a[i] != 0){
			-- a[i];
			++ c[i];
			-- sum;
		}else{
			++ n;
		}
		
		++ i;
		i %= m;
	}

	for (int i = 0; i < m; ++ i){
		printf("%d\n", c[i]);
	}

	return 0;
}
