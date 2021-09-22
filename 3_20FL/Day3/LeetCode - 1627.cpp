// Runtime: 292 ms, faster than 98.76% of C++ online submissions for Graph Connectivity With Threshold.
// Memory Usage: 65.2 MB, less than 5.85% of C++ online submissions for Graph Connectivity With Threshold.
class Solution {
public:
    int f[10005];
    void init_f(int n){
        for (int i=1;i<=n;++i) f[i]=i;
    }
    int find(int n){
        if (f[n]!=n) f[n]=find(f[n]);
        return f[n];
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        init_f(n);
        for (int i=threshold+1;i<=n;++i){
            for (int j=i;j<=n;j+=i){
                f[find(j)]=find(i);
            }
        }
        vector<bool> ans;
        for (int i=0;i<queries.size();++i){
            ans.push_back(find(queries[i][0])==find(queries[i][1]));
        }
        return ans;
    }
};