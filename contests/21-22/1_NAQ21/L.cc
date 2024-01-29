#include <algorithm>
#include <cstdio>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

#define ull unsigned long long

int n, m;
vector<int> e[100006];

inline ull choose3(ull x) {
	if (x < 3) return 0;
	return x * (x - 1) * (x - 2);
}

inline int intersect(const vector<int>& a, const vector<int>& b) {
	int ans = 0;
	int i = 0, j = 0;
	const int la = a.size(), lb = b.size();

	while (i < la && j < lb) {
		if (a[i] < b[j]) ++ i;
		else if (b[j] < a[i]) ++ j;
		else {++ ans, ++ i, ++j;}
	}

	return ans;
}

inline ull count(int u1){
	ull ans = 0;

	const ull s1 = e[u1].size() - 1;
	if (s1 < 1) return 0;

	for (const int u2: e[u1]) {
		const ull s2 = e[u2].size() - 1;
		if (s2 < 3) continue;

		// This will TLE
		// const ull sx = intersect(e[u1], e[u2]);

		vector<int> x;
		set_intersection(
			e[u1].begin(), e[u1].end(), 
			e[u2].begin(), e[u2].end(), 
			back_inserter(x));
		const ull sx = x.size();

		ans += (s1 - sx) * choose3(s2);
		ans += sx * choose3(s2-1);
	}

	return ans;
}

int main(){
	ull ans = 0;
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; ++ i){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i = 1; i <= n; ++ i) {
		sort(e[i].begin(), e[i].end());
	}

	for (int i = 1; i <= n; ++ i){
		ans += count(i);
	}

	printf("%llu\n", ans / 6);
	return 0;
}