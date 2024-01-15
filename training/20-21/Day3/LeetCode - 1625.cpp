class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_map<string,bool> in;
        string tmp,f,ans="Z";
        int l=s.length(),i;
        
        q.push(s);
        in[s]=1;
        while(!q.empty()){
            f=q.front();
            q.pop();
            if (f<ans) ans=f;
            
            tmp=f.substr(l-b,b)+f.substr(0,l-b);
            if (!in[tmp]){
                in[tmp]=1;
                q.push(tmp);
            }
            
            tmp=f;
            for (i=1;i<l;i+=2){
                tmp[i]=tmp[i]+a;
                if (tmp[i]>'9') tmp[i]-=10;
            }
            if (!in[tmp]){
                in[tmp]=1;
                q.push(tmp);
            }
        }
        return ans;
    }
};