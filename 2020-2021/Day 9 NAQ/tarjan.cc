#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

struct node {
	int v,next;
}edge[1001];
int DFN[1001],LOW[1001];
int stack[1001],heads[1001],visit[1001],cnt,tot,idx;

void add(int x,int y){
	edge[++cnt].next=heads[x];
	edge[cnt].v = y;
	heads[x]=cnt;
	return ;
}
void tarjan(int x){
	DFN[x]=LOW[x]=++tot;
	stack[++idx]=x;
	visit[x]=1;
	for(int i=heads[x];i!=-1;i=edge[i].next){
		if(!DFN[edge[i].v]) {
			tarjan(edge[i].v);
			LOW[x]=min(LOW[x],LOW[edge[i].v]);
		}else if (visit[edge[i].v ]){ 
			LOW[x]=min(LOW[x],DFN[edge[i].v]);
		}
	}
	if(LOW[x]==DFN[x]){
		do{
			printf("%d ",stack[idx]);
			visit[stack[idx]]=0;
			idx--;
		}while(x!=stack[idx+1]);
	printf("\n");
	}
	return ;
}
int main(){
	memset(heads,-1,sizeof(heads));
	int n,m;
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!DFN[i])  tarjan(i);
	return 0;
}