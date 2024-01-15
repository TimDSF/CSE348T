// Credit: Tim Dong
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[300005];
int dp[2][64];

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    int ans = 0;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++ i) {
        int j = 1 << a[i]; // current tool
        for (int k = 1; k <= 7; ++ k) {
            if ((j & k) != j) continue;
            int l2 = k ^ j;  // drop after use
            int l1 = (j << 3) | l2;  // use current

            dp[i % 2][l2] = max(dp[1 - i % 2][l1] + 1, dp[1 - i % 2][k] + 1);
            dp[i % 2][l1] = max(dp[1 - i % 2][l1] + 1, dp[1 - i % 2][k] + 1);
            ans = max(dp[i % 2][l1], ans);
            ans = max(dp[i % 2][l2], ans);
        }
        for (int k = 1; k < 64; ++ k) {
            dp[i % 2][k] = max(dp[1 - i % 2][k], dp[i % 2][k]);
        }
    }

    printf("%d\n", ans);
    return 0;
}