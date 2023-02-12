#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
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

void backtrack(vector<int>& b, vector<char>& bb, int v, const vector<vector<int>>& e) {
	if (!bb[v]) return;
	add(b, v, -1); bb[v] = 0;
	for (int u : e[v]) {
		if (!bb[u]) continue;
		backtrack(b, bb, u, e);
	}
}

void solve() {
	int n;
	scanf("%d", &n);

	vector<int> d(n + 1, 0); // 0 is win state
	vector<vector<int>> e(n + 1, vector<int>());

	vector<int> b(n + 1, 0);
	vector<char> bb(n + 1, 0);

	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &d[i]);
		int v = i + d[i];
		if (1 <= v && v <= n) {
			e[v].push_back(i);
		} else {
			e[0].push_back(i);
		}
	}

	queue<int> q; q.push(0);
	vector<char> visited(n + 1, false); visited[0] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			add(b, v, 1); bb[v] = 1;
			q.push(v);
		}
	}

	fill(visited.begin(), visited.end(), 0);
	long long ans = 0;
	int v = 1, vis = 0;
	while (!visited[v]) {
		visited[v] = true; vis += 1;
		backtrack(b, bb, v, e);
		ans += n + 1;
		ans += sum(b, n);
		v += d[v];
		if (v < 1 || v > n) {
			ans += ((long long) (2 * n + 1)) * (n - vis);
			break;
		}
	}

	printf("%lld\n", ans);

	return;
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}