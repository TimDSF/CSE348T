class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        pair<int,int> a[1005];
        int f[1005]={0},l,r,m,total=0,i,j;
        int N=scores.size();
        
        for (i=0;i<N;++i){
            a[i]=make_pair(ages[i],scores[i]);
        }
        sort(a,a+N);
        
        for (i=0;i<N;++i){
            f[i]=a[i].second;
            for (j=0;j<i;++j){
                if (a[j].second<=a[i].second) f[i]=max(f[i],f[j]+a[i].second);
            }
            total=max(total,f[i]);
        }
        return total;
    }
};