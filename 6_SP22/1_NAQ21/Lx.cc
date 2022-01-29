#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

#define ull unsigned long long

int n, m;
ull ans;
vector<int> e[100005];
unordered_set<int> s[100005];

ull count(int u1){
	ull ans = 0;

	int s1 = e[u1].size();
	for (int i = 0; i < s1; ++ i){

		int u2 = e[u1][i], s2 = e[u2].size() - 1;
		if (s2 < 3) continue;

		for (int j = 0; j < s1; ++ j){
			if (i == j) continue;

			int u3 = e[u1][j], m = s2;
			if (s[u2].count(u3)) -- m;
			if (m < 3) continue;

			ans += (unsigned long long) m * (m-1) * (m-2);
		}
	}

	return ans;
}

int main(){
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; ++ i){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
		s[u].insert(v);
		s[v].insert(u);
	}

	for (int i = 1; i <= n; ++ i){
		ans += count(i);
	}

	printf("%llu\n", ans / 6);
	return 0;
}
