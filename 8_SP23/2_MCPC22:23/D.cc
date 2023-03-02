#include <cstdio>
using namespace std;
int n, k;
int main() {
    long long c = 0;
    int ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i) {
        int tmp = i;
        while (tmp) {
            c *= 10;
            tmp /= 10;
        }
        c += i;
        c %= k;
        if (c == 0) ++ ans;
    }
    printf("%d\n", ans);
    return 0;
}