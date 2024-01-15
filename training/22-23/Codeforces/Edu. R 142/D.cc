#include <cstdio>
#include <unordered_set>
using namespace std;

int N, n, m, p[50001][11], inv[50001][11];

int main() {
	scanf("%d\n", &N);

	while (N--) {
		scanf("%d%d", &n, &m);
		unordered_set<unsigned long long> g;

		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				scanf("%d", &p[i][j]);
				--p[i][j];
				inv[i][p[i][j]] = j;
			}
			unsigned long long loc = 1;
			for (int j = 0; j < m; ++ j) {
				loc = loc * 10 + inv[i][j];
				g.insert(loc);
			}
		}
		for (int i = 0; i < n; ++ i) {
			unsigned long long loc = 1;
			bool found = false;
			for (int j = 0; j < m; ++ j) {
				loc = loc * 10 + p[i][j];
				if (g.find(loc) == g.end()) {
					printf("%d ", j);
					found = true;
					break;
				}
			}
			if (!found) {
				printf("%d ", m);
			}
		}
		printf("\n");
	}
	return 0;
}