#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	char b[3][3];
	for (int i = 0; i < 3; ++ i) {
		getchar();
		for (int j = 0; j < 3; ++ j) {
			scanf("%c", &b[i][j]);
		}
	}
	for (int i = 0; i < 3; ++ i) {
		if (b[i][0] != '.' && b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
			printf("%c\n", b[i][0]);
			return;
		}
	}
	for (int j = 0; j < 3; ++ j) {
		if (b[0][j] != '.' && b[0][j] == b[1][j] && b[1][j] == b[2][j]) {
			printf("%c\n", b[0][j]);
			return;
		}
	}
	if (b[0][0] != '.' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
		printf("%c\n", b[0][0]);
		return;
	}
	if (b[0][2] != '.' && b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
		printf("%c\n", b[0][2]);
		return;
	}
	printf("DRAW\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
	return 0;
}