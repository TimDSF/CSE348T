#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, m, h; scanf("%d%d%d", &n, &m, &h);
	vector<int> ti(m);
	vector<pair<int,int>> pl(n);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			scanf("%d", &ti[j]);
		}
		sort(ti.begin(), ti.end());
		int po = 0, cu = 0, sc = 0;
		for (int j = 0; j < m; ++ j) {
			cu += ti[j];
			int ns = sc + cu;
			if (cu <= h) {
				++ po;
				sc = ns;
			} else {
				break;
			}
		}
		pl[i] = {po, sc};
	}
	int ans = 1;
	for (int i = 1; i < n ; ++ i) {
		if (pl[i].first > pl[0].first || pl[i].first == pl[0].first && pl[i].second < pl[0].second) {
			++ ans;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}