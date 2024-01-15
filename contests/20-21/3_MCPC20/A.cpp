// Credit: Yiheng Yao
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
vi nums;
int max_cost = 999999999;
int dp[9][9];
int main(){
	for (int i=0;i<9;++i) nums.push_back(i);
	// Preprocess counts
	string s;
	cin >> s;
	int first_num = s[0]-'1';
	for (int i=0;i<s.length()-1;++i){
		int start = s[i]-'1';
		int end = s[i+1]-'1';
		dp[start][end]++;
//		dp[end][start]++;
	}
//	for (int i=0;i<9;++i){
//		for (int j=0;j<9;++j) printf("%d ", dp[i][j]);
//		printf("\n");
//	}
	// Iterate through all pairs
	do{
		// Compute costs
		int cost = 0;
		for (int i=0;i<nums.size();++i){
			if (nums[i] == first_num) cost+=i;
			for (int j=i+1;j<nums.size();++j){
				cost += dp[nums[i]][nums[j]]*(j-i);
				cost += dp[nums[j]][nums[i]]*(j-i);
			}
		}
//		if (cost < max_cost){
//			for (int i: nums){
//				printf("%d ", i+1);
//			}
//			printf("| %d\n", cost);
//			max_cost = cost;
//		}
		max_cost = min(cost, max_cost);
	}
	while(next_permutation(nums.begin(), nums.end()));
	printf("%d\n", max_cost+s.length());
	return 0;
}
