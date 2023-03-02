#include <cstdio>
#include <algorithm>
using namespace std;

int n, N, L, R;
int a[60005], p[60005], dp[60005][1005];

int main() {
    int mx = 0x80000000, mn = 0x7fffffff;
    scanf("%d%d%d", &n, &L, &R);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
        p[i] = a[i] + p[i - 1];
    }
    N = n + R;
    for (int i = n + 1; i <= N; ++ i) {
        a[i] = 0;
        p[i] = p[i - 1];
    }

    for (int i = 1; i <= N; ++ i) {
        for (int l = L; l <= R; ++ l) {
            int j = l - L;
            if (i < l) {
                dp[i][j] = p[i] > 0;
            } else {
                dp[i][j] = dp[i - l][j] + ((p[i] - p[i - l]) > 0);
            }
            if (i >= n) {
                mx = max(dp[i][j], mx);
                mn = min(dp[i][j], mn);
            }
        }
    }

    printf("%d %d\n", mn, mx);
    return 0;
}