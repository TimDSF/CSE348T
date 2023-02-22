#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

// VARIABlES

// Toll Roads
int n, m, q;
vector<int> us;
vector<pair<int,int>> ans;
vector<pair<int,int>> toll_2_id;

// Disjoint Union
vector<int> fa;  // disjoint union
vector<int> sz;

// Kruskal's
vector<pair<int,pair<int,int>>> edges;
vector<vector<pair<int,int>>> te;  // minimum spanning tree edges

// Heavy-Light Decomposition
vector<int> parent;
vector<int> hchild;

vector<vector<pair<int,int>>> hpaths;
vector<pair<int,int>> htop;
vector<int> pid;
vector<int> pidx;

// Lowest-Common Ancestor
int lg, t;
vector<int> t1, t2; 
vector<vector<int>> up;

// Sparse Table
vector<vector<vector<int>>> st;
vector<int> lg2;

// ALGORITHMS

// Disjoint Union
int get_fa(int u) {
	if (fa[u] == u) return u;
	return fa[u] = get_fa(fa[u]);
}

// Lowest Common Ancestor
void dfs(int u, int rt) {
	t1[u] = ++ t;

	up[u][0] = rt;
	for (int i = 1; i <= lg; ++ i) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}

	for (pair<int,int> e : te[u]) {
		int v = e.first;
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
	for (int i = lg; i >= 0; -- i) {
		if (!is_ancester(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}

// Heavy-Light Decomposition
int dfs(int u) {
	int size = 1;
	int max_size = 0;

	for (pair<int,int> e : te[u]) {
		int v = e.first;
		int w = e.second;
		if (v == parent[u]) continue;
		parent[v] = u;
		int c_size = dfs(v);
		if (c_size > max_size) {
			max_size = c_size;
			hchild[u] = v; 
		}
		size += c_size;
	}

	return size;
}

void decomp(int u, int w0, int h) {
	if (h == u) {
		pid[u] = hpaths.size();
		pidx[u] = 0;
		hpaths.push_back(vector<pair<int,int>>{{u, w0}});
	} else {
		pid[u] = pid[h];
		pidx[u] = pidx[h] + 1;
		hpaths[pid[u]].push_back({u, w0});
	}

	for (pair<int,int> e : te[u]) {
		int v = e.first;
		int w = e.second;
		if (v == parent[u]) continue;
		if (v == hchild[u]) {
			htop[v] = {hpaths[pid[u]][0].first, max(w, htop[u].second)};
			decomp(v, w, u);
		} else {
			htop[v] = {u, w};
			decomp(v, 0, v);
		}
	}
}

int get_max_toll(int u, int v) {
	int p = lca(u, v), i = pid[p], ans = 0;

	while (pid[u] != i) {
		ans = max(htop[u].second, ans);
		if (u == htop[u].first) break;
		u = htop[u].first;
	}
	while (pid[v] != i) {
		ans = max(htop[v].second, ans);
		if (v == htop[v].first) break;
		v = htop[v].first;
	}

	int l = min(pidx[u], pidx[v]) + 1, 
		r = max(pidx[u], pidx[v]), 
		lg = lg2[r - l + 1];
	if (r < l) return ans;
	ans = max(max(st[i][lg][l], st[i][lg][r - (1 << lg) + 1]), ans);
	return ans;
}

// Sparse Table
void build(vector<pair<int,int>>& arr, vector<vector<int>>& st) {
	int n = arr.size();
	for (int i = 0; i < n; ++ i) {
		st[0][i] = arr[i].second;
	}
	for (int j = 1; j <= lg; ++ j) {
		for (int i = 0; i + (1 << j) - 1 < n; ++ i) {
			st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
		}
	}
}

// main
int main() {
	scanf("%d%d%d", &n, &m, &q);

	// init
	te.assign(n, vector<pair<int,int>>());
	fa.resize(n);
	sz.resize(n);
	for (int i = 0; i < n; ++ i) {
		fa[i] = i;
		sz[i] = 1;
	}
	lg2.resize(n + 1);
	lg2[1] = 0; lg2[2] = 1;
	for (int i = 3; i <= n; ++ i) {
		lg2[i] = lg2[i / 2] + 1;
	}
	parent.resize(n);
	hchild.resize(n);
	htop.resize(n);
	pid.resize(n);
	pidx.resize(n);
	lg = ceil(log2(n));
	t1.resize(n); 
	t2.resize(n);
	up.assign(n, vector<int>(lg + 1));
	us.resize(q);
	toll_2_id.resize(q);
	ans.assign(q, pair<int,int>());

	// read
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u; --v;
		edges.push_back({w, {u, v}});
	}

	sort(edges.begin(), edges.end());

	// Kruskal's
	for (int i = 0, found = 0; i < edges.size() && found < n - 1; ++ i) {
		int w = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		// printf("%d-%d : %d\n", u, v, w);

		if (get_fa(u) != get_fa(v)) {
			fa[get_fa(v)] = fa[get_fa(u)];
			te[u].push_back({v, w});
			te[v].push_back({u, w}); 
			++found;
		} 
	}

	// Lowest Common Ancestor
	dfs(0, 0);

	// Heavy-Light Decomposition
	dfs(0);
	decomp(0, 0, 0);

	// printf("\nHeavy Chains:\n");
	// for (int i = 0; i < hpaths.size(); ++ i) {
	// 	printf("%d: ", i);
	// 	for (pair<int,int> u : hpaths[i]) {
	// 		printf("%d(%d) ", u.first, u.second);
	// 	}
	// 	printf("\n");
	// }
	// printf("\nNode\tChain\tIndex\thtop\tweight\n");
	// for (int i = 0; i < n; ++ i) {
	// 	printf("%d\t%d\t%d\t%d\t%d\n", i, pid[i], pidx[i], htop[i].first, htop[i].second);
	// }
	// printf("\n");

	// Sparse Table
	st.assign(hpaths.size(), vector<vector<int>>());
	for (int i = 0; i < hpaths.size(); ++i) {
		st[i].assign(lg2[hpaths[i].size()] + 1, vector<int>(hpaths[i].size()));
		build(hpaths[i], st[i]);
		// for (int j = 0; j < st[i].size(); ++ j) {
		// 	for (int k = 0; k < st[i][j].size(); ++ k) {
		// 		printf("%d ", st[i][j][k]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
	}
	// printf("\n");

	// Delayed Calculation
	for (int i = 0; i < q; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		us[i] = u;
		ans[i].first = get_max_toll(u, v);
		// printf("  => %d\n", ans[i].first);
		toll_2_id[i] = {ans[i].first, i};
	}

	sort(toll_2_id.begin(), toll_2_id.end());

	// Second Round Kruskal's
	for (int i = 0; i < n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}

	// for (int j = 0; j < q; ++ j) {
	// 	printf("%d @ %d\n", toll_2_id[j].first, toll_2_id[j].second);
	// }

	int j = 0;
	for (int i = 0, found = 0; i < edges.size() && found < n - 1;) {
		int toll = toll_2_id[j].first;

		for (; i < edges.size() && edges[i].first <= toll && found < n - 1; ++ i) {
			int w = edges[i].first;
			int u = edges[i].second.first;
			int v = edges[i].second.second;

			if (get_fa(u) != get_fa(v)) {
				sz[get_fa(u)] += sz[get_fa(v)];
				fa[get_fa(v)] = fa[get_fa(u)];
				te[u].push_back({v, w});
				te[v].push_back({u, w}); 
				++found;
			} 
		}

		for (; j < q && toll_2_id[j].first <= toll; ++ j) {
			int i = toll_2_id[j].second, u = us[i];
			ans[i].second = sz[get_fa(u)];
		}
	}

	for (; j < q; ++ j) {
		int i = toll_2_id[j].second, u = us[i];
		ans[i].second = sz[get_fa(u)];
	}

	for (int i = 0; i < q; ++ i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}