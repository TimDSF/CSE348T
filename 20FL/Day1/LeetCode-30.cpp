class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {        
        int ls=s.length(),nw=w.size(),lw=w[0].length();
        
        unordered_map<string,int> cnt,exp;
        int ttl=0,sat=0;
        vector<int> ans;
        
        int b,i,j,k;
        string tmp;
        
        for (i=0;i<nw;++i){
            if (exp.find(w[i])==exp.end()) ++ttl;
            ++exp[w[i]];
        }
        
        for (b=0;b<lw;++b){
            cnt.clear();
            sat=0;
            
            i=b;j=b+nw*lw;  // [i,j) sliding window
            if (j>ls) continue;
            
            for (k=0;k<nw;++k){
                tmp=s.substr(i+k*lw,lw);
                ++cnt[tmp];
                if (exp.find(tmp)!=exp.end()){
                    if (cnt[tmp]==exp[tmp]) ++sat; 
                    else if (cnt[tmp]==exp[tmp]+1) --sat;
                }
            }
            if (sat==ttl) ans.push_back(i);
            
            while(j+lw<=ls){                
                tmp=s.substr(i,lw);
                --cnt[tmp];
                if (exp.find(tmp)!=exp.end()){
                    if (cnt[tmp]==exp[tmp]) ++sat; 
                    else if (cnt[tmp]==exp[tmp]-1) --sat;
                }
                
                tmp=s.substr(j,lw);
                ++cnt[tmp];
                if (exp.find(tmp)!=exp.end()){
                    if (cnt[tmp]==exp[tmp]) ++sat; 
                    else if (cnt[tmp]==exp[tmp]+1) --sat;
                }
                
                i+=lw;
                j+=lw;
                
                if (sat==ttl) ans.push_back(i);
            }
        }
        return ans;
    }
};