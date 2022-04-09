#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		int n, m = 0;
		long long tmp = 1, dif, a[205], sum = 0, sum1 = 0, sum2 = 0;
		vector<int> a1, a2;

		scanf("%d", &n);

		// log_2 10^9 = 29.8
		for (int i = 0; i < min(30, n); ++ i){
			printf("%lld ", tmp);
			a[m ++] = tmp;
			sum += tmp;
			tmp <<= 1;
		}

		for (int i = 3; m < n; ++ i){
			if ((i & (-i)) != i){
				a[m ++] = i;
				sum += i;
				printf("%d ", i);
			}
		}
		printf("\n");
		fflush(stdout);

		for (int i = 0; i < n; ++ i){
			scanf("%lld", &tmp);
			sum += tmp;
			a[m ++] = tmp; 
		}

		sort(a, a+m, greater<int>());
		for (int i = 0 ; i < m; ++ i){
			if ((a[i] & (-a[i])) != a[i]){
				if (sum1 < sum2){
					sum1 += (long long) a[i];
					a1.push_back(a[i]);
				}else{
					sum2 += (long long) a[i];
					a2.push_back(a[i]);
				}
			}
		}

		if (sum1 < sum2){
			dif = sum / 2 - sum1;
			for (int i: a1){
				printf("%d ", i);
			}	
		}else{
			dif = sum / 2 - sum2;
			for (int i: a2){
				printf("%d ", i);
			}	
		}

		tmp = 1;
		while (tmp <= dif){
			if (tmp & dif){
				printf("%lld ", tmp);
			}
			tmp <<= 1;
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}