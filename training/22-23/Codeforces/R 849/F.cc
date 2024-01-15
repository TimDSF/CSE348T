#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

void add(vector<int>& BIT, int idx, int del) {
    for (; idx < BIT.size(); idx += idx & (-idx)) {
        BIT[idx] += del;
    }
}
int sum(vector<int>& BIT, int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        ans += BIT[idx];
    }
    return ans;
}

int a[200005];

void solve() {
	int n, q;
	scanf("%d%d", &n, &q);

	vector<int> bit(n + 5, 0);

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < q; ++ i) {
		int c, x, l, r;
		scanf("%d", &c);
		if (c == 1) {
			scanf("%d%d", &l, &r);
			add(bit, l, 1);
			add(bit, r + 1, -1);
		} else {
			scanf("%d", &x);
			int num = sum(bit, x);

			for (int j = 0; j < num; ++ j) {
				int sum = 0;
				while (a[x]) {
					sum += a[x] % 10;
					a[x] /= 10;
				}
				a[x] = sum;
				if (sum < 10) break;
			}

			printf("%d\n", a[x]);

			if (num == 0) continue;
			add(bit, x, - num);
			add(bit, x + 1, num);
		}
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}