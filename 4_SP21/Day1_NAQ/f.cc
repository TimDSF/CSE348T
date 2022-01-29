#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int n;
string s;
int main(){
	int i;
	scanf("%d\n",&n);
	for (i=0;i<n;++i){
		getline(cin,s);
		if (s.substr(0,10) == "Simon says") cout << s.substr(10) << '\n';
	}
	return 0;
}