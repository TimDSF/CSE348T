#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n,m,n2,dr[7],dis2[7][7],dis[200005];
vector< pair<int,int> > e[200005]; // e[ fn ] = [ < to , wi> ]
priority_queue< pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; // < dis, pos>

int main(){
	int i,j,u,v,w,w2,vis[8]={0,1,2,3,4,5,6,7};
	long long ans=0x7f7f7f7f,cur;
	unordered_set<int> tmp;

	scanf("%d%d",&n,&m);
	for (i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	
	tmp.insert(1);
	for (i=0;i<7;++i){
		scanf("%d",&u);
		tmp.insert(u);
	}

	for (unordered_set<int>::iterator it=tmp.begin(); it != tmp.end();++it,++n2){
		dr[n2] = *it;
	}
	if (n2 == 1){
		printf("0\n");
		return 0;
	}

	for (i=0;i<n2;++i){
		if (dr[i] == 1){
			swap(dr[i],dr[0]);
			break;
		}
	}

	for (i=0;i<n2;++i){
		memset(dis,0x7f,sizeof(dis));
		dis[dr[i]] = 0;
		q.push(make_pair(0,dr[i]));

		while(!q.empty()){
			w = q.top().first;
			u = q.top().second;
			q.pop();
			if (dis[u] != w) continue;

			for (j=0;j<e[u].size();j++){
				v = e[u][j].first;
				w2 = e[u][j].second + w;
				if (w2 < dis[v]){
					dis[v] = w2;
					q.push(make_pair(w2,v));
				}
			}
		}
		for (j=0;j<n2;++j){
			if (dis[dr[j]] == 0x7f7f7f7f){
				printf("-1\n");
				return 0;
			}
			dis2[i][j]=dis[dr[j]];	
		}
	}

	do{
		cur = 0;
		for (i=1;i<n2;++i){
			cur += dis2[vis[i-1]][vis[i]];
		}
		ans = min(ans,cur);
	}while(next_permutation(vis+1,vis+n2));

	printf("%lld\n",ans);

	return 0;
}