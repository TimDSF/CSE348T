#include <iostream>
using namespace std;


int a, b, c;
int ans = 0x7fffffff;

void check(int x) {
	if (x >= 0) {
		ans = min(x, ans);
	}
}

int main(){
	cin >> a >> b >> c;
	check((a + b) + c);
	check((a + b) - c);
	check((a + b) * c);
	if ((a + b) % c == 0) check((a + b) / c);
	check((a - b) + c);
	check((a - b) - c);
	check((a - b) * c);
	if ((a - b) % c == 0) check((a - b) / c);
	check((a * b) + c);
	check((a * b) - c);
	check((a * b) * c);
	if ((a * b) % c == 0) check((a * b) / c);
	if (a % b == 0) check((a / b) + c);
	if (a % b == 0) check((a / b) - c);
	if (a % b == 0) check((a / b) * c);
	if (a % b == 0 && (a / b) % c == 0) check((a / b) / c);

	cout << ans << "\n";
	return 0;
}