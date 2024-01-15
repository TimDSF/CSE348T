#include <cstdio>
#include <stack>
#define N 105
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			printf("-1\n");
			continue;
		}
		n = (n - 1) / 2;
		stack<int> s;
		while (n != 1) {
			if (n % 2 == 1) s.push(2);
			else s.push(1);
			n /= 2;
		}
		printf("%d\n2 ", s.size() + 1);
		while (!s.empty()) {
			printf("%d ", s.top());
			s.pop();
		}
		printf("\n");
	}
	return 0;
}