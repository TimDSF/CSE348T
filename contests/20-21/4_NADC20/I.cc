#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int n,ans1=0,ans2=0,ans3=0;
int t[24][60][60];
string s;

int main(){
	memset(t,0,sizeof(t));

	int i,j,k,l,num,c0,c1,c2,left,right;
	vector<int> c[3];
	bool ast[3],itv;

	scanf("%d",&n);
	cin.get();

	for (i=0;i<n;++i){
		getline(cin,s);
		s+=' ';
		
		l = s.length();
		j=0;num=0;
		c[0].clear();c[1].clear();c[2].clear();
		ast[0]=0;ast[1]=0;ast[2]=0;itv=0;
		
		for (k=0; k<l; ++k){
			if ('0' <= s[k] && s[k] <= '9'){
				num *= 10;
				num += s[k] - '0';
			}else{
				if (s[k] == '-'){
					left = num;
					itv = 1;
				}else if (itv){
					right = num;
					for (num = left; num <= right; ++num){
						c[j].push_back(num);
					}
					itv = 0;
					if (s[k] == ' ') ++j;
				}else{
					if (s[k] == '*'){
						ast[j] = 1;
					}else{ // ','' or ' '
						c[j].push_back(num);
						if (s[k] == ' ') ++j;
					}
				}
				num = 0;
			}
		}

		for (j=0;j<3;++j){
			if (ast[j]){
				c[j].clear();
				l = (j == 0 ? 24 : 60);
				for (num=0; num<l; ++num) c[j].push_back(num);
			}
		} 

		ans2 += c[0].size() * c[1].size() * c[2].size();

		for (c0=0; c0<c[0].size(); ++c0){
			for (c1=0; c1<c[1].size(); ++c1){
				for (c2=0; c2<c[2].size(); ++c2){
					t[c[0][c0]][c[1][c1]][c[2][c2]] += 1;
				}
			}
		}
		
	}

	for (i=0; i<24; ++i){
		for (j=0; j<60; ++j){
			for (k=0; k<60; ++k){
				ans1 += (t[i][j][k] ? 1 : 0);
				ans3 += t[i][j][k];
			}
		}
	}

	printf("%d %d\n",ans1,ans3);
	return 0;
}