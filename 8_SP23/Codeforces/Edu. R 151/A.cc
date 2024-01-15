#include <cstdio>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		int n, k, x;
		scanf("%d%d%d", &n, &k, &x);
		if (k == 1) {
			printf("NO\n");
			continue;
		} else if (k == 2) {
			if (x == 1) {
				if (n % 2 == 0) {
					printf("YES\n");
					printf("%d\n", n / 2);
					for (int i = 0; i < n / 2; ++ i) {
						printf("2 ");
					}
					printf("\n");
				} else {
					printf("NO\n");
				}
				continue;
			} else {
				printf("YES\n");
				printf("%d\n", n);
				for (int i = 0; i < n; ++ i) {
					printf("1 ");
				}
				printf("\n");
			}
		} else {
			if (x == 1) {
				if (n == 1) {
					printf("NO\n");
				} else if (n == 2) {
					printf("YES\n");
					printf("1\n");
					printf("2\n");
				} else if (n == 3) {
					printf("YES\n");
					printf("1\n");
					printf("3\n");
				} else {
					int n2 = n / 2, r = n % 2;
					if (r == 0) {
						printf("YES\n");
						printf("%d\n", n2);
						for (int i = 0; i < n2; ++ i) {
							printf("2 ");
						}
						printf("\n");
					} else {
						printf("YES\n");
						printf("%d\n", n2);
						for (int i = 1; i < n / 2; ++ i) {
							printf("2 ");
						}
						printf("3\n");
					}
				}
			} else {
				printf("YES\n");
				printf("%d\n", n);
				for (int i = 0; i < n; ++ i) {
					printf("1 ");
				}
				printf("\n");
			}
		}
	}
	return 0;
}