#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		int x1, x2, x3, y1, y2, y3;
		
		scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

		if (x1 > x3) {
			x1 = - x1; 
			x2 = - x2; 
			x3 = - x3; 
		}
		if (y1 > y3) {
			y1 = - y1;
			y2 = - y2;
			y3 = - y3;
		}
		
		int ans = 1;
		
		if (x1 <= x2 && x2 <= x3) {
			ans += x2 - x1;
		} else if (x3 < x2) {
			ans += x3 - x1;
		}

		if (y1 <= y2 && y2 <= y3) {
			ans += y2 - y1;
		} else if (y3 < y2){
			ans += y3 - y1;
		}

		printf("%d\n", ans);
	}
	return 0;
}