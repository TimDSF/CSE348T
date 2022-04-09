#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
int t, n, a[100005], f[100005];
vector<int> e[100005];

void build(int u){
	int sz = e[u].size(), v;
	// printf("build %d: %d\n", u, sz);

	for (int i = 0; i < sz; ++ i){
		v = e[u][i];
		// printf("%d %d %d\n", u, v, f[v]);
		if (! f[v]){
			// printf("(%d %d)\n", u, v);

			f[v] = u;
			build(v);
		}
	}
}

bool test(int u, int v){
	int fu[4], fv[4];

	fu[0] = u;
	fv[0] = v;

	for (int i = 1; i < 4; ++ i){
		fu[i] = f[fu[i-1]];
		fv[i] = f[fv[i-1]];
	}
	// printf("%d %d %d %d : %d %d %d %d\n", fu[0], fu[1], fu[2], fu[3], fv[0], fv[1], fv[2], fv[3]);
	for (int i = 0; i < 4; ++ i){
		for (int j = 0 ; j < 4 - i; ++ j){
			if (fu[i] == fv[j]){
				return 1;
			}
		}
	}

	return 0;
}

int main(){
	scanf("%d", &t);

	int u, v;

	while (t --){
		scanf("%d", &n);
		// printf("n=%d\n", n);
		
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; ++ i){
			e[i].clear();
		}
		
		for (int i = 1; i < n; ++ i){
			// printf("i=%d\n", i);
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}

		// printf("-\n");
		// root = 0;
		f[1] = 1;
		build(1);
		// for (int i = 1; i <=n ; ++ i){
		// 	printf("%d => %d\n", i, f[i]);
		// }

		bool failed = 0;

		scanf("%d", &a[0]);
		for (int i = 1; i < n; ++ i){
			scanf("%d", &a[i]);
			if (failed) continue;
			if (! test(a[i-1], a[i])){
				printf("0\n");
				failed = 1;
			}
		}
		if (! failed){
			printf("1\n");
		}

		// printf("--------\n");
	}

	return 0;
}