#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define INF (INT_MAX / 2)
using namespace std;

int read_binary(int n) {
	getchar();
	int res = 0; char c;
	for (int i = 0; i < n; ++ i) {
		scanf("%c", &c);
		res = (res << 1) + (c == '1');
	}
	return res;
}

void solve() {
	int n, m, s;
	scanf("%d%d", &n, &m);
	s = read_binary(n);
	int N = (1 << n);
	vector<int> d(m), c0(m), c1(m);
	for (int i = 0; i < m; ++ i) {
		scanf("%d", &d[i]);
		c0[i] = read_binary(n); c1[i] = read_binary(n);
	}

	vector<vector<pair<int,int>>> e(N);  // e[u] = [pair<v, w>, ...]
	for (int u = 1; u < N; ++ u) {
		for (int i = 0; i < m; ++ i) {
			int v = (u & (~c0[i])) | c1[i];
			e[u].push_back({v, d[i]});
		}
	} 
	
	vector<bool> vis(N, false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;  // pair<dis, u>
	vector<int> dis(N, INF);
	dis[s] = 0; q.push({0, s});
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto ed : e[u]) {
			int v = ed.first, w = ed.second;
			if (dis[v] > dis[u] + w) {
		        dis[v] = dis[u] + w;
		        q.push({dis[v], v});
			}
		}
	}
	printf("%d\n", dis[0] == INF ? -1 : dis[0]);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}