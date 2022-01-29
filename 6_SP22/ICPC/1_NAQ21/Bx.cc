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

int main(){
	scanf("%lf %lf %lf %lf %lf %lf %d", &sx, &sy, &sz, &bx, &by, &bz, &n);
	double fx = bx - sx;
	double fy = by - sy;
	double fz = bz - sz;

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

		double tx = sx - px, ty = sy - py, tz = sz - pz;
		double tmp = ip(tx, ty, tz, fx, fy, fz) / n2(fx, fy, fz);
		double nx = tx - tmp * fx, ny = ty - tmp * fy, nz = tz - tmp * fz;

		if (ip(nx, ny, nz, dx, dy, dz) < 0){
			tx -= nx; ty -= ny; tz -= nz;
			// printf("1: %lf %lf %lf %lf\n", n2(nx, ny, nz), r2, n2(fx, fy, fz), n2(tx, ty, tz));
			if (n2(nx, ny, nz) < r2 && n2(fx, fy, fz) >= n2(tx, ty, tz) && ip(fx, fy, fz, tx, ty, tz) > 0){
				printf("Surrender\n");
				return 0;
			}
		}else{
			nx = fy * dz - fz * dy;
			ny = fz * dx - fx * dz;
			nz = fx * dy - fy * dx;

			if (n2(nx, ny, nz) < 0.0001){
				tx = sx - px, ty = sy - py, tz = sz - pz;
				tmp = ip(tx, ty, tz, fx, fy, fz) / n2(fx, fy, fz);
				tx -= tmp * fx; ty -= tmp * ty; tz -= tmp * tz;
				if (n2(tx, ty, tz) < r2 && ip(dx, dy, dz, bx - px, by - py, bz - pz) > 0){
					printf("Surrender\n");
					return 0;
				}
			}else{
				tx = sx - tx;
				ty = sy - ty;
				tz = sz - tz;
				
				tmp = ip(nx, ny, nz, tx, ty, tz) / n2(nx, ny, nz);
				tx = px + tmp * nx - sx;
				ty = py + tmp * ny - sy;
				tz = pz + tmp * nz - sz;
				// printf("2: %lf %lf %lf %lf\n", tmp * tmp * n2(nx, ny, nz), r2, n2(fx, fy, fz), n2(tx, ty, tz));
				if (tmp * tmp * n2(nx, ny, nz) < r2 && n2(fx, fy, fz) >= n2(tx, ty, tz) && ip(fx, fy, fz, tx, ty, tz) > 0){					
					printf("Surrender\n");
					return 0;
				}
			}
		}
	}

	printf("Go\n");
	return 0;
}