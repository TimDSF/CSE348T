#include <algorithm>
#include <cstdio>
#define N 100005
using namespace std;

int n, k, c;
int t[N], s[N];

int counts[N];
bool adv[N];

int main(){
	int total = 0;
	scanf("%d%d%d", &n, &k, &c);

	for (int i = 0; i < n; ++ i) {
		scanf("%d%d", &t[i], &s[i]);
		if (counts[s[i]] < c && total < k) {
			adv[i] = true;
			++counts[s[i]];
			++total;
		}
	}

	for (int i = 0; i < n; ++ i) {
		if (total == k) break;
		if (!adv[i]) {
			adv[i] = true;
			++total;
		}
	}

	for (int i = 0; i < n; ++ i) {
		if (adv[i]) {
			printf("%d\n", t[i]);
		}
	}

	return 0;
}