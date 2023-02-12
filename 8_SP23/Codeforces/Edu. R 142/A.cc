#include <cstdio>
using namespace std;

int N, n, h[10005];
int main() {
	scanf("%d", &N);

	while (N--){
		int cnt_one = 0, cnt_more = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &h[i]);
			if (h[i] == 1) {
				++cnt_one;
			} else {
				++cnt_more;
			}
		}

		printf("%d\n", (cnt_one+1)/2 + cnt_more);
	}
	
	return 0;
}