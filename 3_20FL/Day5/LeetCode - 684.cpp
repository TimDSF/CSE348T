class Solution {
public:
    void init(vector<int> &fa,int n){
        for (int i=1;i<=n;++i) fa[i]=i;
    }
    int find(vector<int> &fa,int x){
        if (fa[x]!=x) fa[x]=find(fa,fa[x]);
        return fa[x];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m=edges.size(),n=m,u,v,i;
        
        vector<int> ans(2);
        vector<int> fa(n+1);
        
        init(fa,n);
        
        for (i=0;i<m;++i){
            u=edges[i][0];
            v=edges[i][1];
            if (find(fa,u)==find(fa,v)){
                ans[0]=min(u,v);
                ans[1]=max(u,v);
            }
            fa[fa[u]]=fa[v];
        }
        return ans;
    }
};