#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<long long, int>> x;
long long n, lo, hi;
vector<long long> ans;

void dfs(int i, long long cur) {
	if (i == x.size()) {
		if (lo <= cur && cur <= hi) ans.push_back(cur);
		return;
	}
	long long fut = cur;
	for (int p = 0; p <= x[i].second; ++ p) {
		dfs(i + 1, fut);
		fut *= x[i].first;
	}
}

int main() {
	long long k, p;
	scanf("%lld%lld%lld", &n, &k, &p);
	lo = (n / p) + (n % p != 0);
	hi = k;

	unordered_map<long long, int> po;

	long long rem = n;
	for (long long x = 2; x <= sqrt(rem);) {
		if (rem % x == 0) {++ po[x]; rem /= x;}
		else ++ x;
	}
	if (rem != 1) ++po[rem];

	for (const auto &[f, p] : po) x.push_back({f, p});

	dfs(0, 1);

	printf("%zu\n", ans.size());
	sort(ans.begin(), ans.end());
	for (long long x : ans) printf("%lld\n", x);

	return 0;
}