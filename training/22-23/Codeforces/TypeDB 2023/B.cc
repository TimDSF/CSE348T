#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

void solve() {
	int n, sqrt_n;
	scanf("%d", &n);
	sqrt_n = sqrt(n);
	vector<char> prime(sqrt_n + 1, true);
	vector< pair<int, int> > ps;
	for (int i = 2; i <= sqrt_n; ++ i) {
		if (prime[i]) {
			int j = i;
			while (j <= sqrt_n) {
				prime[j] = false;
				j += i;
			}

			int cnt = 0;
			while (n % i == 0) {
				++ cnt;
				n /= i;
			}

			ps.push_back({cnt, i});
		}
	}

	if (n != 1) {
		ps.push_back({1, n});
	}

	sort(ps.begin(), ps.end(), greater< pair<int,int> >());
	ps.push_back({0, 0});

	long long prod = 1, ans = 0;
	for (int i = 0; i < ps.size() - 1; ++ i) {
		int p = ps[i].first;
		int np = ps[i + 1].first;
		int a = ps[i].second;

		prod *= a;

		if (p != np) {
			ans += prod * (p - np);
		}
	}

	printf("%lld\n", ans);
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}