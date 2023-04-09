#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		c -= a;
		d -= b;
		printf("%d\n", (d >= 0 && c <= d) ? (d + d - c) : (-1));
	}
	return 0;
}