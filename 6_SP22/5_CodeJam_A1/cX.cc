#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int d[10][1680][1680];

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		int e, w, tmp, ans, idx;
		char a[10][9], s[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int ss[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		
		scanf("%d%d", &e, &w);
		for (int i = 0; i < e; ++ i){
			for (int j = 0; j < w; ++ j){
				scanf("%d", &tmp);
				for (; tmp > 0; -- tmp){
					a[i][s[i] ++] = j;
				}
			}
		}
		// printf("1\n");

		for (int i = 1; i < e; ++ i){
			int j = 0;
			do{
				int k = 0;
				do{
					tmp = 0;
					int ub = min(s[i-1], s[i]), l;
					for (l = 0; l < ub; ++ l){
						if (a[i-1][l] != a[i][l]) break;
					}
					tmp += s[i-1] - l;
					tmp += s[i] - l;

					d[i][j][k] = tmp;

					++ k;
				}while(next_permutation(a[i], a[i] + s[i]));
				ss[i] = k;
				
				++ j;
			}while(next_permutation(a[i-1], a[i-1] + s[i-1]));
			ss[i - 1] = j;
		}

		// printf("2\n");
		int ops[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		tmp = 0;

		for (int i = 1; i < e; ++ i){
			tmp += d[i][0][0];
		}
		ans = tmp;
		// printf("tmp: %d\n", tmp);

		while (1){
			// printf("%d %d\n", ops[0], ops[1]);
			int idx = e - 1;
			while (idx >= 0 && ops[idx] == ss[idx] - 1){
				// printf("  idx=%d\n", idx);
				if (idx != 0) {
					tmp -= d[idx][ops[idx-1]][ops[idx]];
					// printf("  -\n");
				}
				ops[idx] = 0;
				-- idx;
			}
			if (idx == -1) break;
			if (idx != 0) {
				tmp -= d[idx][ops[idx-1]][ops[idx]];
				// printf("  -\n");
			}
			++ ops[idx];

			for (int i = idx; i < e; ++ i){
				tmp += d[i][ops[i-1]][ops[i]];
			}

			// printf(" tmp: %d\n", tmp);

			if (tmp < ans) ans = tmp;
		}

		printf("Case #%d: %d\n", t, ans + s[0] + s[e-1]);
	}
	return 0;
}