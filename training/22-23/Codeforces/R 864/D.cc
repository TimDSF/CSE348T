#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#define N 100005
using namespace std;

class Cmp {
public:
	inline bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
		return (a.first > b.first) || (a.first == b.first && a.second < b.second);
	}
};

int n, m;
int a[N], fa[N], sz[N];
long long im[N];
set<pair<int, int>, Cmp> hc[N]; // <size, idx>
vector<vector<int>> e;

pair<int, long long> dfs(int u) {
	int size = 1;
	long long imp = a[u];

	for (int v : e[u]) {
		if (v == fa[u]) continue;
		fa[v] = u;
		auto [c_size, c_im] = dfs(v);
		hc[u].insert({c_size, v});
		size += c_size;
		imp += c_im;
	}

	sz[u] = size;
	im[u] = imp;

	return {size, imp};
}

void print() { 
	for (int i = 1; i <= n; ++ i) {
		printf("%d: ", i);
		for (auto it = hc[i].begin(); it != hc[i].end(); ++ it) {
			printf("(%d,%d) ", it->first, it->second);
		}
		printf("\n");
	}
}

void rotate(int u) {
	if (hc[u].empty()) return;

	int f = fa[u];
	auto [_, h] = *hc[u].begin();

	// u
	hc[f].erase({sz[u], u});
	hc[u].erase(hc[u].begin());
	sz[u] -= sz[h]; im[u] -= im[h];
	fa[u] = h;

	// h
	sz[h] += sz[u]; im[h] += im[u]; 
	fa[h] = f;
	hc[h].insert({sz[u], u});

	// f
	hc[f].insert({sz[h], h});
}

int main() {
	scanf("%d%d", &n, &m);
	e.resize(n + 1, vector<int>());
	memset(fa, 0x7f, sizeof(fa));

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	fa[1] = 0;
	dfs(1);

	for (int i = 0; i < m; ++ i) {
		int c, x;
		scanf("%d%d", &c, &x);
		if (c == 1) {
			printf("%lld\n", im[x]);
			continue;
		} 

		rotate(x);
	}

	return 0;
}