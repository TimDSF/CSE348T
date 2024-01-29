#include <cstdio>
#include <vector>
using namespace std;

int n, ln;

vector<vector<int>> edges;
vector<int> parent;
vector<int> hchild;

vector<vector<int>> hpaths;
vector<int> htop;
vector<int> pid;
vector<int> pidx;
vector<vector<int>> ledges;

int dfs(int u) {
	int size = 1;
	int max_size = 0;

	for (int v : edges[u]) {
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

void decomp(int u, int h) {
	if (h == u) {
		pid[u] = hpaths.size();
		pidx[u] = 0;
		hpaths.push_back(vector<int>{u});
	} else {
		pid[u] = pid[h];
		pidx[u] = pidx[h] + 1;
		hpaths[pid[u]].push_back(u);
	}

	for (int v : edges[u]) {
		if (v == parent[u]) continue;
		if (v == hchild[u]) {
			htop[v] = hpaths[pid[u]][0];
			decomp(v, u);
		} else {
			ledges.push_back(vector<int>());
			ledges[pid[u]].push_back(hpaths.size());
			htop[v] = u;
			decomp(v, v);
		}
	}
}

int main() {
	scanf("%d", &n);

	edges.assign(n, vector<int>());
	parent.resize(n);
	hchild.resize(n);
	htop.resize(n);
	pid.resize(n);
	pidx.resize(n);
	ledges.assign(1, vector<int>());

	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(0);
	decomp(0, 0);

	printf("\nHeavy Chains:\n");
	for (int i = 0; i < hpaths.size(); ++ i) {
		printf("%d: ", i);
		for (int u : hpaths[i]) {
			printf("%d ", u);
		}
		printf("\n");
	}
	printf("\nNode\tChain\tIndex\thtop\n");

	for (int i = 0; i < n; ++ i) {
		printf("%d\t%d\t%d\t%d\n", i, pid[i], pidx[i], htop[i]);
	}

	printf("\nLight Edges:\n");
	for (int i = 0; i < ledges.size(); ++ i) {
		printf("%d: ", i);
		for (int j = 0; j < ledges[i].size(); ++ j) {
			printf("%d ", ledges[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}