#include <cmath>
#include <cstdio>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", (long long) sqrt(n - 1));
	}
	return 0;
}
