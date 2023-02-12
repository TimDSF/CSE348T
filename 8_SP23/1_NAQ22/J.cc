#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

#define INF 0x7fffffff
#define S 0
#define T 499999

using namespace std;

int n, m;
vector<int> e[500000];
vector<int> fa(500000);
unordered_map<int, int> w;

inline int ha(const int u, const int v) {
	return (u << 15) + v;
}

inline int idx(int i, int j, int t, int l) {
	// printf("(%d %d %d %d => %d) ", i, j, t, l, (t * 2 + l) * 400 + i * 20 + j + 1);
	return (t * 2 + l) * 400 + i * 20 + j + 1;
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
			if (fa[v] == -1 && w.at(ha(u, v))) {
				fa[v] = u;
				int ff = min(f, w.at(ha(u, v)));
				if (v == t) {
					return ff;
				}
				q.push({v, ff});
			}
		}
	}

	return 0;
}

void add_edge(const int u, const int v) {
	e[u].push_back(v);
	e[v].push_back(u);
	w[ha(u, v)] = 1;
	w[ha(v, u)] = 0;
	// printf("%d -> %d\n", u, v);
}

const int di[4] = {0, 1, -1, 0};
const int dj[4] = {1, 0, 0, -1};

int main() {
	int t;
	int max_flow = 0;
	char g[25][25];

	scanf("%d%d%d", &n, &m, &t); getchar();

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			scanf("%c", &g[i][j]);
			if (g[i][j] == 'P') {
				add_edge(S, idx(i, j, 0, 0));
			}
		}
		getchar();
	}

	for (int tt = 0; tt <= t; ++ tt) {
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				if (g[i][j] == '#') continue;
				
				add_edge(idx(i, j, tt, 0), idx(i, j, tt, 1));

				if (g[i][j] == 'E') {
					add_edge(idx(i, j, tt, 1), T);
				} else {
					if (tt == t) continue;
					add_edge(idx(i, j, tt, 1), idx(i, j, tt + 1, 0));
					for (int d = 0; d < 4; ++ d) {
						int ii = i + di[d], jj = j + dj[d];
						if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
						if (g[ii][jj] == '#') continue;
						add_edge(idx(i, j, tt, 1), idx(ii, jj, tt + 1, 0));
					}
				}
			}
		}
	} 

	while (int new_flow = bfs(S, T, fa)) {
		max_flow += new_flow;
		int v = T;
		while (v != S) {
			int u = fa[v];
			w[ha(u, v)] -= new_flow;
			w[ha(v, u)] += new_flow;
			v = u;
		}
	}

	printf("%d\n", max_flow);
	return 0;
}