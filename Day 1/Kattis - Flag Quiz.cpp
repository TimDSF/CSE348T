#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
int n,m,dif[100];
vector<int> ans;
vector<string> v[100];
int main(){
	int i,j,k,l,mn;
	int a[100];
	string line,tmp;
	getline(cin,line);
	scanf("%d",&n);
	cin.get();
	for (i=0;i<n;++i){
		getline(cin,line);
		line+=",";
		l=line.length();
		tmp="";
		k=0;
		for (j=0;j<l;++j){
			if (line[j]==','){
				j++;
				v[i].push_back(tmp);
				tmp="";
			}else{
				tmp+=line[j];
			}
		}
	}
	for (i=0;i<n;++i){
		mn=0;
		for (j=0;j<n;++j){
			if (i==j) continue;
			l=0;
			for (k=0;k<v[i].size();++k){
				l+=v[i][k]!=v[j][k];
			}
			if (mn<l) mn=l;
		}
		dif[i]=mn;
	}
	mn=0x7fffffff;
	for (i=0;i<n;++i){
		if (dif[i]<mn){
			mn=dif[i];
			ans.clear();
			ans.push_back(i);
		}else if (dif[i]==mn){
			ans.push_back(i);
		}
	}
	for (i=0;i<ans.size();++i){
		for (j=0;j<v[i].size();++j){
			cout<<v[ans[i]][j];
			if (j!=v[i].size()-1) printf(", ");
		}
		printf("\n");
	}
	return 0;
}
