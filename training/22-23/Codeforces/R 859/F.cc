#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#define N 25005
using namespace std;

int t;
int n, m;

inline long long Hash(int i, int j, int di, int dj) {
	return    (long long) (dj + 1) / 2
			+ (long long) (di + 1) / 2 * 2
			+ (long long) (j) * 4
			+ (long long) (i) * 4 * N; 
}

int main() {
	scanf("%d", &t);
	while (t --) {
		int i, j, p, q, di, dj, ans = 0;
		unordered_set<long long> visited;
		scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &p, &q);
		string dir;
		cin >> dir;

		if (dir[0] == 'D') di = 1; else di = -1;
		if (dir[1] == 'R') dj = 1; else dj = -1;

		bool okay = true;
		while (okay) {
			int si = (p - i) / di , sj = (q - j) / dj;
			if (si == sj && si >= 0) {
				break;
			}
			
			int s = min(di == 1 ? n - i : i - 1, dj == 1 ? m - j : j - 1);
			i += di * s;
			j += dj * s;
			if (i == 1) di = 1;
			if (i == n) di = -1;
			if (j == 1) dj = 1;
			if (j == m) dj = -1;

			++ ans;

			long long h = Hash(i, j, di, dj);
			if (!visited.insert(h).second) {
				okay = false;
			}
		}
		if (okay) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}