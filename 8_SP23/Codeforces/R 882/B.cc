#include <cstdio>
#include <vector>
using namespace std;
void solve() {
	int n, tar = -1, cur = -1, ans = 0;
	scanf("%d", &n);
	vector<int> a(n);

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		tar = tar & a[i];
	}

	if (tar) {
		printf("1\n");
	} else {
		for (int i = 0; i < n; ++ i) {
			cur = cur & a[i];
			if (cur == tar) {
				++ ans;
				cur = -1;
			}
		}
		printf("%d\n", ans);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}