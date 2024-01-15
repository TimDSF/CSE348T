class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> e[10000];
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; // <in,i>
        int in[10000];
        int u,v;
        int i,j;
        for (i=0;i<n;++i) in[i]=0;
        
        for (i=0;i<pre.size();++i){
            u=pre[i][0];
            v=pre[i][1];
            e[u].push_back(v);
            in[v]++;
        }
        for (i=0;i<n;++i){
            q.push(make_pair(in[i],i));
        }
        while(!q.empty()){
            i=q.top().second;
            j=q.top().first;
            if (in[i]!=j) {
                q.pop();
                continue;
            }
            if (in[i]!=0) return false;
            q.pop();
            for (j=0;j<e[i].size();++j){
                v=e[i][j];
                in[v]--;
                q.push(make_pair(in[v],v));
            }
        }
        return true;
    }
};