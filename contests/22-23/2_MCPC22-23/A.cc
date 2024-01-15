// Credit: Tim Dong
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int r, f;

int main() {
    scanf("%d%d", &r, &f);
    f %= 2 * r;
    if (r / 2.0 <= f && f <= 3.0 * r / 2) {
        printf("down\n");
    } else {
        printf("up\n");
    }
    return 0;
}