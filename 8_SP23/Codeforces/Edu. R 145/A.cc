#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		unordered_map<int,int> mp;
		string s;
		cin >> s;
		for (char c : s) {
			++ mp[c];
		}
		if (mp.size() == 4) {
			printf("4\n");
		} else if (mp.size() == 3) {
			printf("4\n");
		} else if (mp.size() == 2) {
			if (mp.begin()->second != 2) {
				printf("6\n");
			} else {
				printf("4\n");
			}
		} else {
			printf("-1\n");
		}
	}
	return 0;
}