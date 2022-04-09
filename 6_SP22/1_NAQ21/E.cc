#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string str;
int len;

int main(){
	cin >> str;
	len = str.length();
	int l = str.find('('), r = str.find(')');

	if (l + 1 == r && r * 2 == len){
		printf("correct\n");
	}else{
		printf("fix\n");
	}
	
	return 0;
}