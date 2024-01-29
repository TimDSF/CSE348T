#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#define MOD 9302023
using namespace std;

unordered_map<string, int> words {
	{"zero", 3},
	{"one", 2},
	{"two", 2},
	{"three", 4},
	{"four", 3},
	{"five", 3},
	{"six", 2},
	{"seven", 4},
	{"eight", 4},
	{"nine", 3},
};

string str;

int find(vector<int>& chain, int i) {
	for (int l = 1; l <= 5; ++ l) {
		const string s = str.substr(i, l);
		if (words.find(s) != words.end()) {
			chain.push_back(words[s]);
			return find(chain, i + l - 1);
		}
	}
	return i + 1;
}

pair<int, int> dp(const vector<int>& chain) {
	int n = chain.size();

	// [n][0/1]: first n numbers, pick or not pick last one, best total sum when no adjacent
	vector<vector<int>> dp(n, vector<int>(2, 0));
	vector<vector<int>> ct(n, vector<int>(2, 0));

	dp[0][0] = 0; ct[0][0] = 1;
	dp[0][1] = chain[0]; ct[0][1] = 1;

	int max = chain[0], num = 1;

	for (int i = 1; i < n; ++ i) {
		// find dp[i][0]
		if (dp[i - 1][0] == dp[i - 1][1]) {
			dp[i][0] = dp[i - 1][0];
			ct[i][0] = (ct[i - 1][0] + ct[i - 1][1]) % MOD;
		} else if (dp[i - 1][0] > dp[i - 1][1]) {
			dp[i][0] = dp[i - 1][0];
			ct[i][0] = ct[i - 1][0];
		} else if (dp[i - 1][0] < dp[i - 1][1]) {
			dp[i][0] = dp[i - 1][1];
			ct[i][0] = ct[i - 1][1];
		}

		// maintain ans
		max = dp[i][0];

		// find dp[i][1]
		dp[i][1] = dp[i - 1][0] + chain[i]; 
		ct[i][1] = ct[i - 1][0];

		// maintain ans
		if (dp[i][1] > max) {
			max = dp[i][1];
			num = ct[i][1];
		} else if (dp[i][1] == max) {
			num = (num + ct[i][1]) % MOD;
		}
	}

	return {max, num};
}

int main() {
	cin >> str;

	int ans = 0, num = 1;
	for (int i = 0; i < str.length(); ) {
		vector<int> chain;
		i = find(chain, i);
		if (chain.size()) {
			const auto [max, combo] = dp(chain);
			ans += max;
			num = ((long long) num * combo) % MOD;
		}
	}

	printf("%zu\n%d\n", str.length() - ans, num);
	return 0;
}