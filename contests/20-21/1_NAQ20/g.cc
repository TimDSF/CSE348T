#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int n;
double a;
double ys[100005];

struct Data {
	Data() : x(0), y(0), slope(0.0) {};
	Data(double _x, double _y, double _slope) : x(_x), y(_y), slope(_slope) {};
	double slope;
	double y;
	double x;
};

int main() {
	double ans = 0;
	scanf("%d%lf", &n, &a); a = -a;
	int size = 0;
	vector<Data> q(n + 2);

	for (int x = 1; x <= n; ++ x) {
		scanf("%lf", &ys[x]);
	}
	ys[0] = 0; ys[++n] = 0;

	q[size ++] = Data{0, 0, 0.0};

	for (int i = 1; i <= n; ++ i) {
		double x2 = i;
		double y2 = ys[i];
		
		while (size > 1) {
			double x1 = q[size - 1].x;
			double y1 = q[size - 1].y;
			double s1 = q[size - 1].slope;

			double b = (y1 - y2 + a * (x2 * x2 - x1 * x1)) / (x1 - x2);
			double c = y2 - a * x2 * x2 - b * x2;
			double s2 = 2 * a * x1 + b;

			if (s2 > s1) {
				-- size;
			} else {
				break;
			}
		}

		double x1 = q[size - 1].x;
		double y1 = q[size - 1].y;
		double s1 = q[size - 1].slope;

		double b = (y1 - y2 + a * (x2 * x2 - x1 * x1)) / (x1 - x2);
		double c = y2 - a * x2 * x2 - b * x2;
		double s2 = 2 * a * x2 + b;

		double l = round(- b / a / 2);
		l = max(l, x1); 
		l = min(l, x2);
		double h = a * l * l + b * l + c;
		if (h > ans) ans = h;
		q[size++] = Data{x2, y2, s2};
	}

	printf("%lf\n", ans);

	return 0;
}