#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int t, n;

static int getIndex(int chr) {
	switch (chr) {
	case 'J':
		return 1;
	case 'L':
		return 2;
	case 'S':
		return 4;
	case 'Z':
		return 8;
	case 'I':
		return 16;
	case 'O':
		return 32;
	case 'T':
		return 64;
	default:
		return -1;
	}
}

int main(){
	scanf("%d", &t);

	while (t--) {
		string str;
		cin >> str;

		char a[1005], m[1005];
		int len = str.length();

		for (int i = 0 ; i < len; ++ i){
			a[i] = getIndex(str[i]);
		}
		
		bool succ = 0, fail;
		
		for (int i = 0; i <= 6 && i < len; i++) {
			int lim = ((int)(len - i) / 7) * 7 + i;
			int msk;

			// printf("%d: %d %d   %d %d   %d %d\n", i, 0, i-1, i, lim-1, lim, len-1);
			
			fail = 0;

			// front
			msk = 0;
			for (int j = 0; j < i; j++) {
				if (msk & a[j]) {
					fail = 1;
					break;
				}else{
					msk |= a[j];
				}
			}
			if (fail) continue;
		
			// middle
			for (int j = i; j < lim; j += 7) {
				msk = 0;

				for (int k = j; k < j + 7; ++ k){
					msk |= a[k]; 
				}

				// printf(" %d => %d\n", j, msk);
				if (msk != 0x7f){
					fail = 1;
					break;
				}
			}
			if (fail) continue;

			// back
			msk = 0;
			for (int j = lim; j < len; j++) {
				if (msk & a[j]) {
					fail = 1;
					break;
				}else{
					msk |= a[j];
				}
			}
			if (fail) continue;
			printf("1\n");
			succ = 1;
			break;
		}
		if (! succ){
			printf("0\n");
		}
	}
	
	return 0;
}