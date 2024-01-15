#include <algorithm>
#include <climits>
#include <cstdio>
#include <queue>
#include <vector>
#define N 200005
using namespace std;

typedef struct Edge {
	int u, v, w;
	Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {};
} Edge;
bool cmp(const Edge& e1, const Edge& e2) {
	return e1.w < e2.w;	
}

int get(int x, vector<int>& fa) {
	if (fa[x] != x) fa[x] = get(fa[x], fa);
	return fa[x];
}
void add(int x, int y, vector<int>& fa, vector<int>& sz) {
	if (get(x, fa) == get(y, fa)) return;
	if (sz[x] < sz[y]) swap(x, y); 
	// add x <- y
	sz[fa[x]] += sz[fa[y]];
	fa[fa[y]] = fa[fa[x]];
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		
		vector<int> a(n + 1, 0);
		vector<int> fa(n + 1), sz(n + 1, 1); for (int i = 1; i <= n; ++ i) fa[i] = i;
		vector<Edge> edges;
		queue<int> zeros;

		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
			if (a[i] == 0) {
				zeros.push(i);
			}
		}
		for (int i = 1; i <= m; ++ i) {
			int u, v, w;
			scanf("%d%d", &u, &v);
			w = max(a[u], a[v]);
			edges.push_back({u, v, w});
		}

		int j = 0; 
		bool okay = false;
		sort(edges.begin(), edges.end(), cmp);

		if (zeros.size() == 0) {
			printf("No\n");
			continue;
		}
		for (int i = 0; i < n; ++ i) {
			while (!zeros.empty() && sz[get(zeros.front(), fa)] < i) {
				zeros.pop();
			}
			for (; j < m && edges[j].w <= i; ++ j) {
				int u = edges[j].u, v = edges[j].v;
				if (get(u, fa) == get(v, fa)) continue;
				add(u, v, fa, sz);
			}
			// printf("i=%d\n", i);
			// for (int j = 1; j <= n; ++ j) printf("%d ", fa[j]); printf("\n");
			// for (int j = 1; j <= n; ++ j) printf("%d ", sz[j]); printf("\n");
			
		}
		while (!zeros.empty() && sz[get(zeros.front(), fa)] < n) {
			zeros.pop();
		}
		if (zeros.empty()) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}