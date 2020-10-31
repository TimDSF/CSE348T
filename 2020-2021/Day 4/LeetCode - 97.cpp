class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length()==0) return s2==s3;
        if (s2.length()==0) return s1==s3;
        int i,j,l1=s1.length(),l2=s2.length(),l3=s3.length();
        if (l1+l2!=l3) return false;
        
        bool f[105][105];
        
        f[0][0]=true;
        
        for (i=1;i<=l1;++i){
            f[i][0]=f[i-1][0]&&s1[i-1]==s3[i-1];
        }
        for (j=1;j<=l2;++j){
            f[0][j]=f[0][j-1]&&s2[j-1]==s3[j-1];
        }
        
        for (i=1;i<=l1;++i){
            for (j=1;j<=l2;++j){
                f[i][j]=f[i-1][j]&&s1[i-1]==s3[i+j-1] || f[i][j-1]&&s2[j-1]==s3[i+j-1];
            }
        }
        
        return f[l1][l2];
    }
};