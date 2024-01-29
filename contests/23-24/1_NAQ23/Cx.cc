#include <cstdio>
#include <vector>
#include <unordered_map>
#define N 1000006
#define EPS 0.0000000001L
using namespace std;

int n, k;
int q[N], f[N];

bool failed() {
	vector<vector<int>> exp(N, vector<int>());
	int foods = 0;

	for (int i = 1; i <= n; ++ i) {
		// get food
		foods += q[i];
		exp[f[i]].push_back(i);

		// eat almost no
		if (foods == 0) return true;

		// expire
		for (const int d : exp[i]) {
			foods -= q[d];
		}
	}

	return false;
}

bool test(long double m) {
	vector<vector<int>> exp(N, vector<int>());
	vector<long double> food(N, 0);
	int eat = 1;

	for (int i = 1; i <= n; ++ i) {
		// get food
		food[i] = q[i];
		exp[f[i]].push_back(i);

		// eat
		long double need = m;
		while (eat <= i && need > EPS) {
			if (food[eat] >= need) {
				food[eat] -= need;
				need = 0;
			} else {
				need -= food[eat];
				food[eat] = 0;
				++ eat;	
			}
		}

		if (need > EPS) return false;

		// expire
		for (const int d : exp[i]) {
			food[d] = 0;
		}
	}

	return true;
}

int main() {
	scanf("%d%d", &n, &k);

	long double lo = 0, hi = 0;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &q[i], &f[i]);
		hi = hi + q[i];
	}
	hi /= n;

	if (failed()) {
		printf("-1\n");
		return 0;
	}

	while (hi - lo > EPS) {
		long double m = (lo + hi) / 2;

		if (test(m)) {
			lo = m;
		} else {
			hi = m;
		}
	}

	printf("%.9Lf\n", (long double) lo / k);

	return 0;
}