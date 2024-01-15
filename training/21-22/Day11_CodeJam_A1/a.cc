#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t){
		string str;
		cin >> str;

		printf("Case #%d: ", t);

		int l = str.length(), l_1 = l - 1;

		for (int i = 0; i < l; ++ i){
			int j = i;
			while (j < l_1 && str[j] == str[j+1]){
				++ j;
			}
			if (j < l_1 && str[j] < str[j+1]){
				for (int k = i; k <= j; ++ k){
					printf("%c%c", str[j], str[j]);
				}
			}else{
				for (int k = i; k <= j; ++ k){
					printf("%c", str[j]);
				}
			}
			i = j;
		}
		printf("\n");
	}
	return 0;
}