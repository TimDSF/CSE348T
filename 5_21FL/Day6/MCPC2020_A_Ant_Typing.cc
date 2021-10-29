#include <iostream>
#include <algorithm>

using namespace std;

string s; // input string of digits
int dp[10][10], // dp array: dp[i][j] stores the number of adjacent i-j pair, i < j 
	num[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8}; // location array: num[i] stores the location of i

int main(){
	cin >> s; // input s

	int n = s.length(), ans = 0x7fffffff, st = s[0] - '1'; // ans: optimal solution, st: starting number

	for (int i = 1; i < n; ++ i){ // counting for dp[i][j]
		int c1 = s[i - 1] - '1';
		int c2 = s[i]     - '1';

		if (c1 > c2) ++ dp[c2][c1];
		else if (c1 < c2) ++ dp[c1][c2];
	}

	do{ // iterate all permutations of the digits
		int tmp = num[st]; // tmp: cost of the current permutation, starting with going to the first digit from the leftmost location

		for (int i = 0; i < 8; ++ i){ // iterate through all pairs of adjacent digits
			for (int j = i + 1; j < 9; ++ j){
				tmp += dp[i][j] * abs(num[i] - num[j]); // increase the cost of corresponding pair
			}
		}

		if (tmp < ans) ans = tmp; // maintaining the optimal solution
	}while(next_permutation(num, num + 9)); // go to the next permutation

	printf("%d\n", ans + n); // output answer

	return 0; // return success code 0
}