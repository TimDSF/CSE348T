#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string s;
int l,ans;
int bit[26][100005];

int query(int i,int x){
	int ans=0;
	for (;x>0;x-=x&(-x)){
		ans+=bit[i][x];
	}
	return ans;
}
void update(int i,int x,int d){
	for (;x<=l;x+=x&(-x)){
		bit[i][x]+=d;
	}
}

int main(){
	int i,j,k,le,ri;
	cin>>s;
	l=s.length();
	s='X'+s;
	vector<int> v[26]; // 0-25 for a to z;
	for (i=1;i<=l;i++){
//		printf("%d\n",i);
		v[s[i]-'a'].push_back(i);
		update(s[i]-'a',i,1);
	}
//	printf("111");
	for (i=0;i<26;i++){
		if (v[i].size()==0) continue;
		for (j=0;j<v[i].size();j++){
			ri=j==v[i].size()-1?l:v[i][j+1];
			le=v[i][j];
			for (k=0;k<26;k++){
				if (k==i) continue;
//				printf("%d,%d,%d\n",i,j,k);
				ans+=(query(k,ri)-query(k,le))!=0;
			}
		}
	}
	printf("%d\n",ans);
}