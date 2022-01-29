#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int T,n,a[105];
// l _ _ _ _ r
int func(int n,int x,int y,char l,char r){
	int ans=0;

	if (l=='C' && r=='J') ans = x;
	if (l=='J' && r=='C') ans = y;

	if (n==0) return ans;
	
	ans=min(ans,(n/2)*x + ((n-1)/2)*y + (l=='J'?y:0) + (n%2?(r=='J'?x:0):(r=='C'?y:0))); // CJCJ...
	ans=min(ans,(n/2)*y + ((n-1)/2)*x + (l=='C'?x:0) + (n%2?(r=='C'?y:0):(r=='J'?x:0))); // JCJC...

	return ans;
}
int main(){
	int t,i,x,y,l,cst;
	string s;
	scanf("%d",&T);
	for (t=0;t<T;++t){
		scanf("%d%d",&x,&y);cin >> s;
		vector<int> idx;

		l=s.length();
		for (i=0;i<l;++i){
			if (s[i]!='?') idx.push_back(i);
		}

		cst=0;
		if (idx.size()!=0){
			cst = func(idx[0],x,y,'?',s[idx[0]]) + func(l-idx[idx.size()-1]-1,x,y,s[idx[idx.size()-1]],'?');
		}else{
			cst = func(l,x,y,'?','?');
		}
		for (i=1;i<idx.size();++i){
			cst += func(idx[i]-idx[i-1]-1,x,y,s[idx[i-1]],s[idx[i]]);
		}
		printf("Case #%d: %d\n",t+1,cst);
	}
	return 0;
}