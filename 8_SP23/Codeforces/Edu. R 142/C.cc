#include <cstdio>
#include <cmath>
#include <unordered_map>
using namespace std;

int N, n, a[200005];
int main() {
    scanf("%d", &N);

    while (N--){
        scanf("%d\n", &n);
        bool found = false;
        int prev_a = n, prev_b = -1;
        
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
            mp[a[i]] = i;
        }

        for (int i = (n + 1) / 2; i > 0; -- i) {
            int j = n + 1 - i;
            int cur_a = mp.at(i), cur_b = mp.at(j);
            if (cur_a > cur_b || prev_a < cur_a || cur_b < prev_b) {
                printf("%d\n", i);
                found = true;
                break;
            }
            prev_a = cur_a;
            prev_b = cur_b;
        }

        if (!found) printf("0\n");
    }
    
    return 0;
}