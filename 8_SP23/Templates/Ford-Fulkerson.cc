#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

#define INF 0x7fffffff
#define S 0
#define T (n - 1)

using namespace std;

int n, m;
vector<int> e[100000];
unordered_map<int, int> c;

inline int ha(const int u, const int v) {
	return (u << 15) + v;
}

int bfs(const int s, const int t, vector<int>& fa) {
	fill(fa.begin(), fa.end(), -1);

	fa[s] = s;
	queue<pair<int,int>> q;
	
	q.push({s, INF});

	while (!q.empty()) {
		int u = q.front().first;
		int f = q.front().second;
		q.pop();

		for (int v : e[u]) {
			if (fa[v] == -1 && c.at(ha(u, v))) {
				fa[v] = u;
				int ff = min(f, c.at(ha(u, v)));
				if (v == t) {
					return ff;
				}
				q.push({v, ff});
			}
		}
	}

	return 0;
}

int main() {
	int max_flow = 0;

	scanf("%d%d", &n, &m);
	vector<int> fa(n);

	for (int i = 0; i < m; ++ i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(v);
		c[ha(u, v)] = w;
	}

	while (int new_flow = bfs(S, T, fa)) {
		max_flow += new_flow;
		int v = T;
		while (v != S) {
			int u = fa[v];
			c[ha(u, v)] -= new_flow;
			c[ha(v, u)] += new_flow;
			v = u;
		}
	}
	printf("max_flow: %d\n", max_flow);
}