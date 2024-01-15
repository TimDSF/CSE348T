#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

int n, m;
priority_queue<pair<int,pair<int,int>>, 
	vector<pair<int,pair<int,int>>>, 
	greater<pair<int,pair<int,int>>>> edges;
vector<vector<pair<int,int>>> te;  // minimum spanning tree edges
vector<int> fa;  // disjoint union

int get_fa(int u) {
	if (fa[u] == u) return u;
	return fa[u] = get_fa(fa[u]);
}

int main() {
	scanf("%d%d", &n, &m);

	te.assign(n, vector<pair<int,int>>());
	fa.resize(n);
	for (int i = 0; i < n; ++ i) {
		fa[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges.push({w, {u, v}});
	}

	int found = 0;
	while (found < n - 1) {
		int w = edges.top().first;
		int u = edges.top().second.first;
		int v = edges.top().second.second;
		printf("%d-%d : %d\n", u, v, w);
		edges.pop();

		if (get_fa(u) != get_fa(v)) {
			fa[fa[v]] = fa[fa[v]];
			te[u].push_back({v, w});
			te[v].push_back({u, w});
			printf("  yes\n");
			++found;
		} 
	}

	for (int i = 0; i < n; ++i) {
		printf("%d: ", i);
		for (int j = 0; j < te[i].size(); ++j) {
			printf("%d(%d) ", te[i][j].first, te[i][j].second);
		}
		printf("\n");
	}
}