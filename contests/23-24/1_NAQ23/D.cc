#include <cmath>
#include <algorithm>
#include <cstdio>
# define PI          3.141592653589793238462643383279502884L
using namespace std;

int n, r, w, h;
long double ans;

long double arc(int r, int d) {
	long double angle = acos((long double)d / r) * 2;
	long double sector = r * r * angle / 2;
	long double triangle = sqrt(r * r - d * d) * d;
	long double ans = sector - triangle;
	return ans;
}

long double tri(int r, int d1, int d2) {
	long double angle = acos((long double)d1 / r) + acos((long double)d2 / r) + PI / 2;
	long double sector = r * r * angle / 2;
	long double triangle = d1 * d2 + (sqrt(r * r - d1 * d1) * d1 + sqrt(r * r - d2 * d2) * d2) / 2;
	long double ans = arc(r, d1) + arc(r, d2) + triangle - sector;

	return ans;
}

long double calc(int w, int h, int x, int y, int r) {
	int xx = w - x, yy = h - y;
	long double ans = PI * r * r;

	if (x < r) ans -= arc(r, x);
	if (y < r) ans -= arc(r, y);
	if (xx < r) ans -= arc(r, xx);
	if (yy < r) ans -= arc(r, yy);
	
	if (x * x + y * y < r * r) ans += tri(r, x, y);
	if (xx * xx + y * y < r * r) ans += tri(r, xx, y);
	if (x * x + yy * yy < r * r) ans += tri(r, x, yy);
	if (xx * xx + yy * yy < r * r) ans += tri(r, xx, yy);

	return ans;
}

int main() {
	scanf("%d%d%d%d", &n, &r, &w, &h);

	for (int i = 0; i < n; ++ i) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		ans += calc(w, h, x, y, r) * v;
	}

	printf("%.10Lf", ans / w / h);

	return 0;
}