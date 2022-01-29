#include <cstdio>
#include <cstring>
using namespace std;

int N, n, b[3][3], i, cat, player, winner;

int main(){
	scanf("%d", &N);

	while(N --){
		scanf("%d", &n);

		memset(b, 0, sizeof(b));
		i = 0;
		cat = ((n % 1000) == 777);
		winner = 0;

		for (int p = 0; p < 6; ++ p){
			int d = n % 10; 
			n /= 10;

			for (int k = 0; k < 3; ++ k, ++ i){
				if (d & (1 << k)){
					++ b[i / 3][i % 3];
				}
			}

			if (i == 9) i = 0;
		}
		player = n & 1;

		if (b[0][0] != 0 && b[0][0] == b[0][1] && b[0][0] == b[0][2]){
			winner = b[0][0];
		}else if (b[1][0] != 0 && b[1][0] == b[1][1] && b[1][0] == b[1][2]){
			winner = b[1][0];
		}else if (b[2][0] != 0 && b[2][0] == b[2][1] && b[2][0] == b[2][2]){
			winner = b[2][0];
		}else if (b[0][0] != 0 && b[0][0] == b[1][0] && b[0][0] == b[2][0]){
			winner = b[0][0];
		}else if (b[0][1] != 0 && b[0][1] == b[1][1] && b[0][1] == b[2][1]){
			winner = b[0][1];
		}else if (b[0][2] != 0 && b[0][2] == b[1][2] && b[0][2] == b[2][2]){
			winner = b[0][2];
		}else if (b[0][0] != 0 && b[0][0] == b[1][1] && b[0][0] == b[2][2]){
			winner = b[0][0];
		}else if (b[0][2] != 0 && b[0][2] == b[1][1] && b[0][2] == b[2][0]){
			winner = b[0][2];
		}

		if (winner){
			if (player == 0){
				printf("X wins\n");
			}else{
				printf("O wins\n");
			}
		}else if (cat){
			printf("Cat's\n");
		}else{
			printf("In progress\n");
		}
	}
	return 0;
}