#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int T;

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; ++ t){
		string str;
		cin >> str;
		
		int l = str.length(), sum = 0;
		for (int i = 0; i < l; ++ i){
			sum += str[i] - '0';
		}
		char c = 9 - (sum % 9) + '0';

		printf("Case #%d: ", t);
		if (c == '9') c = '0';
		for (int i = 0; i < l; ++ i){
			if (str[i] <= c || (c == '0' && i == 0)){
				printf("%c", str[i]);
			}else{
				printf("%c%c", c, str[i]);
				c = 127;
			}
		}
		if (c != 127){
			printf("%c", c);
		}
		printf("\n");
	}

	return 0;
}