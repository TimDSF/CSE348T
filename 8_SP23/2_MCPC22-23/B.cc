// Credit: Tim Dong
#include <cstdio>
#include <math.h>
#include <cmath>
#include <algorithm>
#define N 100005
using namespace std;

int n, X;
long long bit[N],val[N];

struct Value {
    long long x, y;
    long long v;
    int i, a;
    Value() : x(0), y(0), v(0), i(0), a(0) {};
    Value(long long xx, long long yy, long long vv, int ii, int aa) : x(xx), y(yy), v(vv), i(ii) , a(aa) {};
} a[N];

long long cross(long long x1, long long y1, long long x2, long long y2) {
    return x1 * y2 - x2 * y1; 
}

bool cmp1(const Value v1, const Value v2) {
    return cross(v1.x, v1.y, v2.x, v2.y) < 0;
}
bool cmp2(const Value v1, const Value v2) {
    return cross(v1.x - X, v1.y, v2.x - X, v2.y) < 0;
}

long long sum(int x) {
    long long ans = 0;
    for (; x <= n; x += x & (-x)) {
        ans += bit[x];
    }
    return ans;
}

void update(int x, long long d) {
    for (; x > 0; x -= x & (-x)) {
        bit[x] += d;
    }
}

int main() {
    scanf("%d%d", &n, &X);

    for (int i = 1; i <= n; ++ i) {
        int x, y;
        long long v;
        scanf("%d%d%lld", &x, &y, &v);
        a[i] = {x, y, v, i, 0};
    }
    sort(a + 1, a + 1 + n, cmp1);
    for (int i = 1; i <= n; ++ i) {
        a[i].a = i;
    }
    sort(a + 1, a + 1 + n, cmp2);

    for (int i = 1; i <= n; ++ i) {
        val[a[i].i] = sum(a[i].a);
        update(a[i].a, a[i].v);
    }

    for (int i = 1; i <= n; ++ i) {
        printf("%lld\n", val[i]);
    }

    return 0;
}