#include <cstdio>
#include <string>
#include <limits>
#include <vector>
#include <iostream>
using namespace std;

void solve() {
	int n, st = 0, min_st;
	long long cur = 0, min_cur = LLONG_MAX;
	
	scanf("%d", &n);
	vector<int> a(n);

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		cur += a[i];
		if (cur >= 0) {
			cur = 0;
			st = i + 1;
		} else {
			if (cur < min_cur) {
				min_cur = cur;
				min_st = st;
			}
		}
	}

	cur = 0;
	for (int i = 0; i < min_st; ++ i) {
		cur += a[i];
	}

	printf("%lld\n", cur);
}
int main() {
	int t; scanf("%d", &t);
	while (t --) {
		solve();
	}
	return 0;
}