#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,t,d;// n: intersections; m: roads; t: repair shops; d: distance without flat tyres
bool r[505]; // r: repair shop or not
long long dist[505][505]; // dist[][]: Floyd–Warshall on all nodes;

int n2,e[505]; // n2: nodes in new graph; e[]: original index for new graph
vector< pair<int,long long> > e2[505]; // edge sets for new graph
long long dis2[505]; //  dis2[]: SPFA distance for new graph 

int main(){
    int i,j,k,u,v; // some temporary variables
    long long w;

    bool in[505]; // in_queue indicator for SPFA

    scanf("%d%d%d%d",&n,&m,&t,&d);

    // repair shop initialization
    for (i=1;i<=t;++i){
        scanf("%d",&u);
        r[u] = 1;
    }
    r[1] = 1;
    r[n] = 1;

    // dist: Floyd–Warshall initialization
    for (i=1;i<=n;++i){
        for (j=1;j<=n;++j){
            dist[i][j] = 0x80000000;
        }
    }
    for (i=1;i<=n;++i){
        dist[i][i] = 0;
    }

    for (i=1;i<=m;++i){
        scanf("%d%d%lld",&u,&v,&w);
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd–Warshall
    for (k=1;k<=n;k++){
        for (i=1;i<=n;++i){
            for (j=1;j<=n;++j){
                dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
            }
        }
    }

    // e: maps indices in new graph to original graph
    for (i=1;i<=n;++i){
        if (r[i]){
            e[++n2] = i;
        }
    }

    // dis2[]: distance from 1; e2: edges
    for (i=1;i<=n2;++i){
        dis2[i] = 0x80000000;
        for (j=1;j<=n2;++j){
            if (dist[e[i]][e[j]] <= d && i != j) e2[i].push_back( make_pair( j, dist[e[i]][e[j]] ) );
        }
    }
    dis2[1] = 0;

    // SPFA
    queue<int> q;
    q.push(1);
    in[1] = 1;

    while(!q.empty()){
        u = q.front();
        q.pop();
        in[u] = 0;
        for (i=0;i<e2[u].size();++i){
            v = e2[u][i].first;
            w = e2[u][i].second;

            if (dis2[v] > dis2[u] + w){
                dis2[v] = dis2[u] + w;
                if (!in[v]){
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    if (dis2[n2]>0x7fffffff){ 
        printf("stuck\n");
    }else{
        printf("%lld\n",dis2[n2]);
    }
    return 0;
}