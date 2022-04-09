#include <cstdio>
using namespace std;

int n, m, a[1000005], sum;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	for (int k = 0; k < m; ++ k){
		int q, s = sum, i = n, j = n+1;
		scanf("%d", &q);
		
		if (q > sum){
			printf("No\n");
			continue;
		}

		while (i != -1){
			if (s == q){
				printf("Yes\n");
				q = -1;
				break;
			}else if (s < q){
				-- j;
				s += a[j];
			}else/* if (s > q)*/{
				s -= a[i];
				-- i;
			}
		}

		if (q != -1){
			printf("No\n");
		}
	}

	return 0;
}