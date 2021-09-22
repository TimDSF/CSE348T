#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

int n,ans = 0;
string str,s;
unordered_map<string,int> mp;

int main(){
	int i,j,k,l,ml,ll;
	scanf("%d",&n);

	for (i=0; i<n; ++i){
		cin >> str;
		l = str.length();

		for (j=0; j<l; ++j){
			s = "";
			for (k=j; k<l; ++k){
				s += str[k];

				if (mp.find(s) == mp.end()){
					mp[s] = 1;
				}else{
					++ mp[s];
				}
				ll = k-j;
				if (mp[s] == n && ll > ans){
					ans = ll;
				}
			}
		}
	}
	printf("%d\n",ans+1);
	return 0;
}