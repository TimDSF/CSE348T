#include <cstdio>
using namespace std;

int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
unsigned long long n, nu = 1, de = 1, g;

unsigned long long gcd(unsigned long long a, unsigned long long b){
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main(){
	unsigned long long tmp = 1;
	int k;

	scanf("%llu", &n);
	
	for (k = 0; ; ++ k){
		tmp *= primes[k];
		if (tmp > n) break;

		nu = nu * (primes[k] - 1);
		de = de * primes[k];
	}

	nu = de - nu;
	g = gcd(nu, de);
	nu /= g;
	de /= g;

	printf("%llu/%llu\n", nu, de);
	return 0;
}