#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int ps[100005];
unordered_set<int> e[100005];

int main(){
	int T;
	srand(time(NULL));

	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		int j = 1, n, k, u, v, p, e1 = 0, e2 = 0, e3 = 0;

		scanf("%d%d", &n, &k);

		for (int i = 1; i <= n; ++ i){
			e[i].clear();
			ps[i] = 0;
		}

		scanf("%d%d", &u, &p);
		ps[u] = p;

		for (int i = 1; i <= k; ++ i){
			if (p == 1){
				bool found = 0;
				for (; j <= n; ++ j){
					if (! ps[j]){
						found = 1;
						cout << "T " << j << endl;
						break;
					}
				}
				if (found){
					scanf("%d%d", &u, &p);
					ps[u] = p;
					continue;
				}else if (e[u].size() >= ps[u] / 2){
					cout << "T " << rand() % n + 1 << endl;
					scanf("%d%d", &u, &p);
					ps[u] = p;
					continue;
				}
			}
			cout << "W" << endl;
			scanf("%d%d", &v, &p);

			ps[v] = p;
			e[u].insert(v);
			e[v].insert(u);

			u = v;
		}

		for (int i = 1; i <= n; ++ i){
			int sz = e[i].size();
			e1 += sz;
			e2 += ps[i] - sz;
			e3 += ps[i] != 0;
		}
		e1 /= 2;

		// cout << "e's: " << e1 << ' ' << e2 << ' ' << e3 << endl;
		cout << "E " << e1 + (n * (n-1) / 2 - e1) * e2 / e3 / (n-1) << endl;
	}
	return 0;
}