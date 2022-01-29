#include <cstdio>
#include <iostream>
using namespace std;
char a[8][8],queen;
int main(){
	int i,j,p,q,cnt;
	bool valid;
	for (i=0;i<8;++i){
		cin >> a[i];
	}
	for (i=0;i<8;++i){
		for (j=0;j<8;++j){
			if (a[i][j]=='.') continue;
			++queen;

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				++p;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				--p;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				++q;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				--q;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				++p;++q;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				++p;--q;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				--p;++q;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}

			cnt = 0;
			p=i;q=j;
			while(0<=p && p<8 && 0<=q && q<8){
				cnt += a[p][q]=='*';
				--p;--q;
			}
			if (cnt != 1){
				printf("invalid\n");
				return 0;
			}
		}
	}
	if (queen==8) printf("valid\n"); else printf("invalid\n");
	return 0;
}