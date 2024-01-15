// Credit: Tim Dong
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define N 200005
using namespace std;

int n, m, a[N], cur = 0, ans = 0;
vector<int> e[N];
unordered_set<int> chain, dropped;
bool finished = false;

void dfs(int u) {
    chain.insert(u);

    if (finished) return;
    while (chain.find(a[cur]) != chain.end()) {
        ++ ans;
        ++ cur;
        if (cur == m) {
            finished = true;
            return;
        }
    }
    if (dropped.find(a[cur]) != dropped.end()) {
        finished = true;
        return;
    }
    for (int v : e[u]) {
        dfs(v);
    }
    while (chain.find(a[cur]) != chain.end()) {
        ++ ans;
        ++ cur;
        if (cur == m) {
            finished = true;
            return;
        }
    }

    chain.erase(u);
    dropped.insert(u);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++ i) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; ++ i) {
        sort(e[i].begin(), e[i].end());
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d", &a[i]);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}