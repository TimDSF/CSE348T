#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int v = 0, y = 0;
	for (int i = 0; i < s.length(); ++ i) {
		v += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
		y += s[i] == 'y';
	}

	printf("%d %d\n", v, v + y);

	return 0;
}