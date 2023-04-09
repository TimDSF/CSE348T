#include <cstdio>
#include <vector>
#define N 200005
using namespace std;
 
int n, q;
int a[N];
long long s1[N], s2[N];
vector<int> c[N];

void dfs(int u, long long a1, long long a2) {
	s1[u] = a1 + a[u];
	s2[u] = a2 + a[u] * a[u];
	for (const int v : c[u]) {
		dfs(v, s1[u], s2[u]);
	}
}

int main(){
	scanf("%d%d", &n, &q);
	
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++ i) {
		int p;
		scanf("%d", &p);
		c[p].push_back(i);
	}
	
	dfs(1, 0, 0);

	for (int i = 0; i < q; ++ i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", (s1[x] * s1[y] - s2[x] - s2[y]) / 2);
	}

	return 0;
}
