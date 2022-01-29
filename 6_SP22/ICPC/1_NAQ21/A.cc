#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

long long n, ans1 = -1, ans2 = -1, d1, d2;
int l, lo = 10, hi = -1, fi;
bool d[10];

int main(){
	scanf("%lld", &n);
	long long tmp = n;
	while (tmp){
		d[tmp % 10] = 1;
		if (tmp < 10) fi = tmp;
		tmp /= 10;
		++ l;
	}

	for (int i = 0; i < 10; ++ i){
		if (d[i] == 0){
			if (i < lo) lo = i;
			if (i > hi) hi = i;
		}
	}

	if (lo == 10){
		printf("Impossible\n");
		return 0;
	}

	if (lo == hi){
		if (lo == 0){
			ans1 = 0;
		}else{
			ans1 = 0;
			if (lo < fi){
				for (int i = 0; i < l; ++ i) ans1 = ans1 * 10 + lo;
			}else{
				for (int i = 1; i < l; ++ i) ans1 = ans1 * 10 + lo;
			}
			ans2 = ans1 * 10 + lo;
		}
	}else{
		for (int i = fi - 1; i >= 0; -- i){
			if (d[i] && i) continue;
			ans1 = i;
			for (int j = 1; j < l; ++ j) ans1 = ans1 * 10 + hi;
			break;
		}
		for (int i = fi + 1; i < 10; ++ i){
			if (d[i]) continue;
			ans2 = i;
			for (int j = 1; j < l; ++ j) ans2 = ans2 * 10 + lo;
			break;
		}
		if (ans2 == -1){
			ans2 = lo == 0 ? 1 : lo;
			for (int j = 0; j < l; ++ j) ans2 = ans2 * 10 + lo;
		}
	}

	d1 = ans1 == -1 ? 0x7fffffffffffffff : abs(ans1 - n);
	d2 = ans2 == -1 ? 0x7fffffffffffffff : abs(ans2 - n);

	// printf("%lld %lld\n", ans1, ans2);

	if (d1 < d2){
		printf("%lld\n", ans1);
	}else if (d1 > d2){
		printf("%lld\n", ans2);
	}else{
		printf("%lld %lld\n", ans1, ans2);
	}

	return 0;
}