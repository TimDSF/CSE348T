#include <unordered_map>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

int n,m,dr[200005];
unordered_map<int,int> dis[128]; // dis[bitmask][u] = min distance to u with dragon bitmask
vector< pair<int,int> > e[200005]; // e[ fn ] = [ < to , wi> ]
priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q; // < dis , <dis, dr> >

int main(){
	int i,j,u,v,w,w2,d,d2,ans=0x7fffffff;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	for (i=0;i<7;++i){
		scanf("%d",&u);
		dr[u] += 1<<i;
	}

	if (dr[1] == 127){
		printf("0\n");
		return 0;
	}

	q.push(make_pair(0,make_pair(1,dr[1])));
	dis[dr[1]][1]=0;
	
	while(!q.empty()){
		w = q.top().first;
		u = q.top().second.first;
		d = q.top().second.second;
		q.pop();

		for (i=0;i<e[u].size();++i){
			v = e[u][i].first;
			w2 = w + e[u][i].second;
			d2 = d | dr[v];
			if (d2 == 127){
				ans = min(ans,w2);
			}

			if (dis[d2].find(v)==dis[d2].end() || w2<dis[d2][v]){
				q.push(make_pair(w2,make_pair(v,d2)));
				dis[d2][v] = w2;
			}
		}
	}
	printf("%d\n",ans==0x7fffffff?-1:ans);
	return 0;
}