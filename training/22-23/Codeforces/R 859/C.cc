#include <cstdio>
#include <vector>
using namespace std;

int t;
int n;

int main() {
	scanf("%d", &t); getchar();
	while (t --) {
		bool okay = true;
		vector<int> p(26, -1);
		scanf("%d", &n); getchar();
		for (int i = 0; i < n; ++ i) {
			char c;
			scanf("%c", &c);
			c -= 'a';
			if (p[c] == -1) {
				p[c] = i % 2;
			} else {
				if (p[c] != i % 2) {
					okay = false;
				}
			}
		}
		if (okay) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}