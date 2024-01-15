#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <cmath>
#define N 100005
using namespace std;

struct Point {
	int x, y;
	Point() : x(0), y(0) {};
	Point(int xx, int yy) : x(xx), y(yy) {};
};

Point c0[N], c1[N];

double dist(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int ccw(Point p1, Point p2, Point p3) {
	int xx0 = p2.x - p1.x, yy0 = p2.y - p1.y;
	int xx1 = p3.x - p2.x, yy1 = p3.y - p2.y;
	return xx0 * yy1 - xx1 * yy0 > 0;
}

int cw(Point p1, Point p2, Point p3) {
	int xx0 = p2.x - p1.x, yy0 = p2.y - p1.y;
	int xx1 = p3.x - p2.x, yy1 = p3.y - p2.y;
	return xx0 * yy1 - xx1 * yy0 < 0;
}

bool cmp(Point p1, Point p2) {
	return p1.x < p2.x;
}

int main(){
	int n, m0, m1;
	Point p0 = Point(1005, 0), p1 = Point(-1005, 0);

	vector<Point> ps;
	unordered_set<int> pos;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		int x, y;
		scanf("%d%d", &x, &y);
		pos.insert((x + 1000) * 10000 + (y + 1000));

	}
	for (int p : pos) {
		int x = p / 10000 - 1000;
		int y = p % 10000 - 1000;
		ps.push_back(Point(x,y));
		if (x < p0.x) {
			p0.x = x; p0.y = y;
		}
		if (x > p1.x) {
			p1.x = x; p1.y = y;
		}
	}

	sort(ps.begin(), ps.end(), cmp);
	c0[0] = p0; m0 = 1; 
	c1[0] = p0; m1 = 1;

	for (int i = 1; i < ps.size(); ++ i) {
		while (m0 >= 2 && !ccw(c0[m0 - 2], c0[m0 - 1], ps[i])) {
			-- m0;
		}
		c0[m0] = ps[i]; ++ m0;

		while (m1 >= 2 && !cw(c1[m1 - 2], c1[m1 - 1], ps[i])) {
			-- m1;
		}
		c1[m1] = ps[i]; ++ m1;
	}

	for (int i = m1 - 2; i > 0; -- i) {
		c0[m0 ++] = c1[i];
	}

	double ans = 0;
	for (int i = 0; i < m0; ++ i) {  // delta: i
		int l = 1, r = m0 - 1;
		double d = 0;
		while (l <= r) {
			int m1 = (l + r) / 2;
			double d1 = dist(c0[i], c0[(m1 + i) % m0]);
			d = max(d, d1);
			if (m1 == l) {
				++ l;
			} else if (m1 == r) {
				-- r;
			} else {
				int m2 = m1 + 1;
				double d2 = dist(c0[i], c0[(m2 + i) % m0]);
				if (d1 < d2) {
					l = m1 + 1;
				} else {
					r = m1 - 1;
				}
			}
		}
		ans = max(ans, d);
	}

	printf("%lf\n", ans);

	return 0;
}