// Credit: Yiheng Yao & Tim Dong
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int adj[26][26];
int n,k;
int max_clique;

struct item{
	int node;
	int v;
	int len;
};

int main(){
	scanf("%d%d", &n, &k);
	for (int i=0;i<n;++i){
		string s;
		cin >> s;
		// Build Graph
		for (int a=0;a<k;++a){
			for (int b=a+1;b<k;++b){
				adj[s[a]-'A'][s[b]-'A']++;
			}
		}
	}
	
//	for (int a=0;a<26;++a){
//		for (int b=0;b<26;++b){
//			printf("%d ", adj[a][b]);
//		}
//		printf("\n");
//	}
	
	for (int i=0;i<26;++i){
		queue<item> q;
		q.push({i, 1<<i, 1});
		while(!q.empty()){
			item c_item = q.front(); q.pop();
			int c = c_item.node;
			int v = c_item.v;
			max_clique = max(max_clique, c_item.len);
			for (int t=0;t<26;++t){
				if (adj[c][t] == n && !(v&(1<<t))){
					q.push({t, v|(1<<t), c_item.len+1});
				}
			}
		}
	}

	printf("%d\n", max_clique);
	
	return 0;
}
