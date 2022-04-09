#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int T;
bool dp[2][100005];
string I, P;

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; ++ t){
		cin >> I >> P;

		int lI = I.length(), lP = P.length(), i = 0, j = 0;

		while (i < lI && j < lP){
			if (I[i] == P[j]) ++ i, ++ j;
			else ++ j;
		}

		printf("Case #%d: ", t);
		if (i == lI){
			printf("%d\n", lP - lI);
		}else{
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
/*
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int T;
bool dp[2][100005];
string I, P;

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; ++ t){
		cin >> I >> P;

		int lI = I.length(), lP = P.length();

		for (int i = 0 ; i <= lP; ++ i){
			dp[0][i] = 1;
		}

		for (int i = 1; i <= lI; ++ i){
			dp[i % 2][0] = 0;
			for (int j = 1; j <= lP; ++ j){
				dp[i % 2][j] = (dp[(i-1) % 2][j-1] && I[i] == P[j]) || dp[i % 2][j-1];
			}
		}

		printf("Case #%d: ", t);
		if (dp[lI % 2][lP]){
			printf("%d\n", lP - lI);
		}else{
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
*/