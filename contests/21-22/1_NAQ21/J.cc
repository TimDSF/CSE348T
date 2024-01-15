#include <cstdio>
#include <iostream>
using namespace std;

int n, a[1005];
string ans;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	
	int shift = 0;
	for (int i = n - 1; i >= 0; -- i){
		a[i] += shift;
		int tmp = a[i];
		while (tmp){
			shift += (tmp & 1);
			tmp >>= 1;
			++ shift;
		}
		shift -= 2;
	}

	for (int i = 0; i < n; ++ i){
		printf("1");

		int tmp = a[i], msk = 1;
		while (tmp){
			tmp >>= 1;
			msk <<= 1;
		}
		msk >>= 2;

		while (msk){
			printf("d+");
			if (a[i] & msk){
				printf("1+");
			}
			msk >>= 1;
		}
	}
	printf("\n");

	return 0;
}
