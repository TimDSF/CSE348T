#include <queue>
#include <cstdio>
#include <algorithm>
#define ft first
#define sd second
using namespace std;
int C,L,ans;
pair<int,int> cow[2505],lot[2505];
// cow=<min,max>, lot=<spf,num>
priority_queue<int,vector<int>,greater<int> > q; 
// <max> of the cows
int main(){
	int i,j;
	scanf("%d%d",&C,&L);
	for (i=0;i<C;++i){
		scanf("%d%d",&cow[i].ft,&cow[i].sd);
	}
	for (i=0;i<L;++i){
		scanf("%d%d",&lot[i].ft,&lot[i].sd);
	}
	sort(cow,cow+C);
	sort(lot,lot+L);
	j=0;
	for (i=0;i<L;++i){
		while(j<C && cow[j].ft<=lot[i].ft){
			q.push(cow[j++].sd);
		}
		while(!q.empty() && lot[i].sd>0){
			if (q.top()>=lot[i].ft){
				++ans;
				--lot[i].sd;
			}
			q.pop();
		}
	}
	printf("%d\n",ans);
	return 0;
}
