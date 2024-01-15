#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int T, len;
string str;

bool dfs(string str, int idx){
	if (idx == len){
		for (int i = 0; i < len - 4; ++ i){
			if (str[i] == str[i+4] && str[i+1] == str[i+3]) return 0;
		}
		for (int i = 0; i < len - 5; ++ i){
			if (str[i] == str[i+5] && str[i+1] == str[i+4] && str[i+2] == str[i+3]) return 0;
		}
		cout << str << "\n";
		return 1;
	}
	if (str[idx] != '?') return dfs(str, idx + 1);
	str[idx] = '0';
	bool res = dfs(str, idx + 1);
	if (res) return 1;
	str[idx] = '1';
	res = dfs(str, idx + 1);
	if (res) return 1;
	str[idx] = '?';
	return 0;
}

int main(){
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		scanf("%d", &len);
		cin >> str;

		printf("Case #%d: ", t);
		if (dfs(str, 0)){
			printf("POSSIBLE\n");
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}