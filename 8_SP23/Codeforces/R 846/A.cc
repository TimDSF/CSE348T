#include <cstdio>
#include <vector>
using namespace std;
int T, n;
int main(){
	scanf("%d", &T);

	while (T--) {
		vector<int> evens, odds;
		int a;

		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a);
			if (a % 2 == 1) {
				odds.push_back(i);
			} else {
				evens.push_back(i);
			}
		}

		if (odds.size() >= 3) {
			printf("YES\n%d %d %d\n", odds[0], odds[1], odds[2]);
		} else if (odds.size() >= 1 && evens.size() >= 2) {
			printf("YES\n%d %d %d\n", odds[0], evens[0], evens[1]);
		} else {
			printf("NO\n");
		}
	}

	return 0;
}