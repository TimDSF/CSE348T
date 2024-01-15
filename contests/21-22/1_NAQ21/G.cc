#include <cstdio>
using namespace std;

int C, N;
bool c[100005];

void print(int t){
	int nt = 1 - t, last = 0, cnt = 0;

	for (int i = 1; i <= C; ++ i){
		if ((i == 1 || c[i-1] == nt) && c[i] == t) last = i;
	}

	for (int i = 1; i <= C; ++ i){
		if ((i == 1 || c[i-1] == nt) && c[i] == t){
			if (cnt){
				if (i == last){
					printf(" and ");
				}else{
					printf(", ");
				}
			}
			printf("%d", i);
			if (i != C && c[i+1] == t){
				printf("-");
			}
			++ cnt;
		} else if (c[i] == t && (i == C || c[i+1] == nt)){
			printf("%d", i);
		}
	}
	printf("\n");
}

int main(){
	int l;
	scanf("%d %d", &C, &N);

	for (int i = 0; i < N; ++ i){
		scanf("%d", &l);
		c[l] = 1;
	}

	printf("Errors: ");
	print(1);

	printf("Correct: ");
	print(0);

	return 0;
}