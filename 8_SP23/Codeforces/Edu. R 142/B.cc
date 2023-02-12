#include <cstdio>
#include <cmath>
using namespace std;

int N;
int main() {
	scanf("%d", &N);

	while (N--){
		int a, b, c, d;
		int sa = 0, sb = 0, ans = 0, tmp;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		sa = sb = ans = a;

		if (ans == 0) {
			printf("1\n");
			continue;
		}

		tmp = min(b, c);
		b -= tmp;
		c -= tmp;
		ans += tmp << 1;
		
		tmp = min(sb, b);
		sb -= tmp;
		b -= tmp;
		ans += tmp;

		tmp = min(sa, c);
		sa -= tmp;
		c -= tmp;
		ans += tmp;

		tmp = min(min(sa, sb), d);
		sa -= tmp;
		sb -= tmp;
		d -= tmp;
		ans += tmp;

		printf("%d\n", ans + ((b + c + d) != 0));
	}
	
	return 0;
}