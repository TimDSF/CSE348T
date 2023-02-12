#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

vector<int> g1[100005], g2[100005], g[100005], c[100005];
bool used[100005];
int ic[100005];
vector<int> order;
int nc;

int id[100005];

void dfs1(int v) {
	used[v] = true;

	for (auto u : g1[v])
		if (!used[u])
			dfs1(u);

	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	c[nc].push_back(v);

	for (auto u : g2[v])
		if (!used[u])
			dfs2(u);
}

long long dfs(int u) {
	long long ans = 1;
	for (int v : g[u]) {
		ans *= dfs(v);
		ans %= MOD;
	}

	ans = (ans + 1) % MOD;
	// printf("%d: %lld\n", u, ans);
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int u = 1; u <= n; ++ u) {
		int v;
		scanf("%d", &v);
		g1[u].push_back(v);
		g2[v].push_back(u);
	}
	
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++)
		if (!used[i])
			dfs1(i);

	memset(used, 0, sizeof(used));
	reverse(order.begin(), order.end());
	for (auto v : order) {
		if (!used[v]) {
			dfs2 (v);

			for (int u : c[nc]) {
				// printf("%d ", u);
				ic[u] = nc;
			}
			// printf("\n");

			++nc;
		}
	}

	for (int i = 0; i < nc; ++ i) {
		for (int u : c[i]) {
			for (int v : g1[u]) {
				if (ic[v] != i) {
					g[ic[v]].push_back(i);
					++ id[i];
					// printf("  %d=%d <- %d\n", i, ic[u], ic[v]);
					// printf("  %d size%d\n", v, g[v].size());
				}
			}
		}
		// printf("\n");
	}

	for (int i = 0; i < nc; ++ i) {
		// printf("%d: %d\n", i, id[i]);
		if (id[i] == 0) {
			g[nc].push_back(i);
			// printf("  %d <- %d\n", i, nc);
		}
	}

	// for (int i = 0; i <= nc; ++ i) {
	// 	printf("%d: ", i);
	// 	for (int v : g[i]) 
	// 		printf("%d ", v); 
	// 	printf("\n");
	// }
	// printf("---\n");

	printf("%lld\n", (dfs(nc) + MOD - 2) % MOD);

	return 0;
}
