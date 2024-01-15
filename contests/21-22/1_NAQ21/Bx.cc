#include <cmath>
#include <cstdio>
using namespace std;

int n;
double sx, sy, sz, bx, by, bz;

double ip(double ax, double ay, double az, double fx, double fy, double fz){
	return ax * fx + ay * fy + az * fz;
}

double n2(double x, double y, double z){
	return x * x + y * y + z * z;
}

void cp(double ax, double ay, double az, double bx, double by, double bz, double *cx, double *cy, double *cz){
	cx = ay * bz - az * by;
	cy = az * bx - ax - bz;
	cz = ax * by - ay * bx;
}

int main(){
	scanf("%lf %lf %lf %lf %lf %lf %d", &sx, &sy, &sz, &bx, &by, &bz, &n);
	double fx = bx - sx, fy = by - sy, fz = bz - sz;

	while (n--){
		int m;
		double px, py, pz, dx, dy, dz, cx, cy, cz, r2 = 0;

		scanf("%lf %lf %lf %lf %lf %lf %d", &px, &py, &pz, &dx, &dy, &dz, &m);

		while (m--){
			scanf("%lf %lf %lf", &cx, &cy, &cz);
			double d2 = n2(px - cx, py - cy, pz - cz);
			if (d2 > r2){
				r2 = d2;
			}
		}

		if (n2(bx - px, by - py, bz - pz) < r2){
			printf("Surrender\n");
			return 0;
		}
		if (n2(sx - px, sy - py, sz - pz) < r2){
			printf("Surrender\n");
			return 0;
		}
		
	}

	printf("Go\n");
	return 0;
}