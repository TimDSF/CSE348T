#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n,f[105],ans,gsize;
bool g[105][105];
string name[105],lang[105];

unordered_map<string,int> langidx;
unordered_set<string> ppl[105];

// SCC
struct node {
	int v,next;
}edge[1001];

int DFN[1001],LOW[1001];
int stack[1001],heads[1001],visit[1001],cnt,tot,idx;

void addEdge(int x,int y){
	edge[++cnt].next=heads[x];
	edge[cnt].v = y;
	heads[x]=cnt;
	return;
}
void tarjan(int x){
	DFN[x]=LOW[x]=++tot;
	stack[++idx]=x;
	visit[x]=1;
	for(int i=heads[x];i!=-1;i=edge[i].next){
		if(!DFN[edge[i].v]){
			tarjan(edge[i].v);
			LOW[x]=min(LOW[x],LOW[edge[i].v]);
		}else if(visit[edge[i].v ]){
			LOW[x]=min(LOW[x],DFN[edge[i].v]);
		}
	}
	if(LOW[x]==DFN[x]){
		int tmp = 0;
		do{
	    	tmp += ppl[stack[idx]].size();
			visit[stack[idx]]=0;
			idx--;
		}while(x!=stack[idx+1]);
		ans = max(ans,tmp);
	}
	return;
}

void addLang(string l){
	if (langidx.count(l) == 0){
		langidx[l]=langidx.size()+1;
	}
}

int main(){
     memset(heads,-1,sizeof(heads));

	string line,word;
	int i,j;
	unordered_set<string>::iterator it;
	int tar;

	scanf("%d",&n);
	cin.get();
	
	for (i=0;i<n;++i) f[i]=i;

	for (i=0;i<n;++i){
		getline(cin,line);
		line += ' ';

		tar=0;

		word="";
		for (j=0;j<line.length();++j){
			if (line[j] != ' ') word += line[j];
			else{
				if (tar == 0){
					name[i]=word;
					++tar;
				}else if (tar == 1){
					lang[i]=word;
					addLang(word);
					ppl[langidx[word]].insert(name[i]);
					++tar;
				}else{
					addLang(word);
					g[langidx[lang[i]]][langidx[word]]=1;
				}
				word="";
			}
		}
	}

	gsize = langidx.size();
	for (i=1;i<=gsize;++i){
		for (j=1;j<=gsize;++j){
			if (g[i][j]) addEdge(i,j);
		}
	}
	ans=0;
	for (i=1;i<=gsize;++i){
		if (!DFN[i]) tarjan(i);
	}
	printf("%d\n",n-ans);
	return 0;
}