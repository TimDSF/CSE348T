#include <queue>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

long long ans;
int n, a[100005]/*, fa[100005], mx[100005]*/;
vector<int> rts;
vector<int> chs[100005];

/*
void calc_max(int u){
	if (chs[u].size() == 0){
		mx[u] = a[u];
		return;
	}
	for (int v: chs[u]){
		calc_max(v);
		mx[u] = max(mx[u], mx[v]);
	}
}
*/

int calc(int u){
	if (chs[u].size() == 0){
		return a[u];
	}
	int min_a = 0x7fffffff;

	for (int v: chs[u]){
		int tmp = calc(v);
		ans += tmp;
		min_a = min(min_a, tmp);
	}

	ans -= min_a;

	return max(min_a, a[u]);
}

int main(){
	int T;

	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		// a: value; fa: father; mx: max in the subtree
		int fa;

		rts.clear();

		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i){
			scanf("%d", &a[i]);
			chs[i].clear();
		}
		for (int i = 1; i <= n; ++ i){
			scanf("%d", &fa);
			if (fa){
				chs[fa].push_back(i);
			}else{
				rts.push_back(i);
			}
		}

		ans = (long long) 0;
		for (int u: rts){
			// calc_max(u);
			ans += calc(u);
		}

		printf("Case #%d: %lld\n", t, ans);

	}
	return 0;
}