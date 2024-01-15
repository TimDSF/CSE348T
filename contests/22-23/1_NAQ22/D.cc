#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[105];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        a[i] = i;
    }

    for (int i = 0; i < m; ++ i) {
        int x;
        cin >> x;
        swap(a[x], a[x+1]);
    }

    for (int i = 1; i <= n; ++ i) {
        cout << a[i] << "\n";
    }

    return 0;
}