class Solution {
public:
    void init(vector<int> &fa,int n){
        for (int i=1;i<=n;++i) fa[i]=i;
    }
    int find(vector<int> &fa,int x){
        if (fa[x]!=x) fa[x]=find(fa,fa[x]);
        return fa[x];
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int m=edges.size(),n=m,u,v,i,j,ans=0,p=0;
        
        vector<int> in(n+2);
        for (i=0;i<m;++i){
            v=edges[i][1];
            ++in[v];
            if (in[v]==2){p=v;break;}
        }
        
        vector<int> fa(n+20);
        
        for (i=m-1;i>=0;--i){
            if (p && edges[i][1]!=p) continue;
            
            init(fa,n);
            bool is_tree=true;
            for (j=0;j<m;++j){
                if (i==j) continue;
                u=edges[j][0];
                v=edges[j][1];
                if (find(fa,v)!=v || find(fa,u)==v){
                    is_tree=false;
                    break;
                }
                fa[v]=u;
            }
            if (is_tree) return edges[i];
        }
        return edges[ans];
    }
};