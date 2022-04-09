#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
	string str;
	int len;
	
	getline(cin, str);
	len = str.length();
	
	int sum = 0;
	for (int i = 0; i < len; ++ i){
		sum += (int) str[i];
	}
	sum /= str.length();

	printf("%c\n", sum);
	return 0;
}
