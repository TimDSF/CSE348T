#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int pi[205];

string str[1005];

void build_table(const string s) {
	int l = s.length();
	pi[0] = 0;
	for (int i = 1; i < l; ++ i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) ++ j;
		pi[i] = j;
	}
}

int main(){
	scanf("%d",&n);

	for (int i = 0; i < n; ++ i){
		cin >> str[i];
	}
	if (n == 1) {
		printf("%d\n", str[0].length());
		return 0;
	}
	
	int ans = 0;
	for (int i = str[0].length(); i > 0; -- i) {
		int mn = 0x7fffffff;

		for (int j = 1; j < n; ++ j) {
			string tmp = str[0].substr(str[0].length() - i) + '#' + str[j];
			build_table(tmp);

			int mx = 0;
			for (int k = i + 1; k < tmp.length(); ++ k) {
				mx = max(mx, pi[k]);
			}
			mn = min(mn, mx);
		}
 		ans = max(ans, mn);
	}

	printf("%d\n", ans);

	return 0;
}