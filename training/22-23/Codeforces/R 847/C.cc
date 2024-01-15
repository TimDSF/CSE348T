#include <cstdio>
#include <unordered_map>
using namespace std;

int a[105], b[105];

void solve() {
	int n;
	scanf("%d", &n);

	unordered_map<int, int> contains;
	int excludes, after = -1, idx = 0x7fffffff;

	for (int i = 0; i < n - 1; ++ i) {
		scanf("%d", &a[i]);
		contains[a[i]] = i;
	}
	for (excludes = 1; excludes <= n; ++ excludes) {
		if (contains.find(excludes) == contains.end()) {
			break;
		}
	}

	for (int k = 1; k < n; ++ k) {
		scanf("%d", &b[0]);
		for (int i = 1; i < n - 1; ++ i) {
			scanf("%d", &b[i]);
			if (b[i - 1] == excludes) {
				if (int it = contains.at(b[i]); it < idx) {
					after = b[i];
					idx = it;
				}
			}
		}
	}

	for (int i = 0; i < n - 1; ++ i) {
		if (a[i] == after) {
			printf("%d ", excludes);
		}
		printf("%d ", a[i]);
	}
	if (after == -1) {
		printf("%d\n", excludes);
	} else {
		printf("\n");
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}