#include <cstdio>
using namespace std;

int main(){
	int T, r, c;

	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		scanf("%d%d", &r, &c);

		printf("Case #%d:\n", t);
		printf("..+");
		for (int i = 1; i < c; ++ i){
			printf("-+");
		}
		printf("\n");
		printf("..|");
		for (int i = 1; i < c; ++ i){
			printf(".|");
		}
		printf("\n");
		printf("+-+");
		for (int j = 1; j < c; ++ j){
			printf("-+");
		}
		printf("\n");

		for (int i = 1; i < r; ++ i){
			printf("|.|");
			for (int j = 1; j < c; ++ j){
				printf(".|");
			}
			printf("\n");
			printf("+-+");
			for (int j = 1; j < c; ++ j){
				printf("-+");
			}
			printf("\n");
		}
	}
}