#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void solve() {
	int n, m, p, b;
	scanf("%d%d%d%d", &n, &m, &p, &b);
	vector<char> token(n + 1, false), bonus(n + 1, false);
	vector<vector<int>> edges(n + 1, vector<int>(0));

	for (int i = 0; i < p; ++ i) {
		int u;
		scanf("%d", &u);
		token[u]++;
	}
	for (int i = 0; i < b; ++ i) {
		int u;
		scanf("%d", &u);
		bonus[u] = true;
	}
	for (int i = 0; i < m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	if (token[1]) {
		printf("YES\n");
		return;
	}

	unordered_set<int> vi;
	vi.insert(1);

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (int v : edges[u]) {
			if (vi.find(v) != vi.end()) continue;
			vi.insert(v);	
			if (token[v]) {
				printf("YES\n");
				return;
			}
			if (!bonus[v]) continue;
			q.push(v);
		}
	}
	printf("NO\n");
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}