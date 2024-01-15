#include <cstdio>
#include <map>
using namespace std;

void solve() {
	int n, ans = 0, prev_size = -100, prev_num = 0;
	map<int, int> counts;
	scanf("%d", &n);

	for (int i = 0; i < n; ++ i) {
		int tmp;
		scanf("%d", &tmp);
		++ counts[tmp];
	}

	for (auto it = counts.begin(); it != counts.end(); ++ it) {
		const int size = it -> first;
		const int num = it -> second;
		if (prev_size + 1 == size) {
			ans += max(num - prev_num, 0);
		} else {
			ans += num;
		}
		prev_size = size;
		prev_num = num;
	}

	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}