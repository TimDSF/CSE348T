#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int n, t = 0, l;
vector<int> t1, t2; 
vector<vector<int>> e, up;

void dfs(int u, int rt) {
	t1[u] = ++ t;

	up[u][0] = rt;
	for (int i = 1; i <= l; ++ i) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}

	for (int v : e[u]) {
		if (v == rt) continue;
		dfs(v, u);
	}

	t2[u] = ++ t;
}

inline bool is_ancester(const int u, const int v) {
	return t1[u] <= t1[v] && t2[u] >= t2[v];
}

int lca(int u, int v) {
	if (is_ancester(u, v)) return u;
	if (is_ancester(v, u)) return v;
	for (int i = l; i >= 0; -- i) {
		if (!is_ancester(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}

int main() {
	scanf("%d", &n);
	l = ceil(log2(n));

	t1.resize(n); t2.resize(n);
	e.assign(n, vector<int>());
	up.assign(n, vector<int>(l + 1));


	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
	}

	dfs(0, 0);

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < l; ++ j) {
			printf("%d ", up[i][j]);
		}
		printf("\n");
	}


	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", lca(u, v));
	}

	return 0;
}