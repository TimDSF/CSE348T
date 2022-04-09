#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int T;

bool test(int num){
	int sum = 0, prod = 1;
	while (num){
		int d = num % 10;
		if (d == 0) return 1;
		sum += d;
		prod *= d;
		num /= 10;
	}
	if (prod % sum == 0){
		return 1;
	}
	return 0;
}

int main(){
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		int a, b, num = 0;
		scanf("%d%d", &a, &b);
		for (int i = a; i <= b; ++ i){
			num += test(i);
		}

		printf("Case #%d: %d\n", t, num);
	}
	return 0;
}