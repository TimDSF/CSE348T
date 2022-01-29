class Solution {
public:
    string decodeString(string s) {
        string ans;
        
        int len = s.length(), cur = 0, st = 0, br = 0;
        
        for (int i = 0; i < len; ++i){
            char ch = s[i];
            
            if (ch == '['){
                if (br == 0) st = i;
                ++ br;
            }else if (ch == ']'){
                -- br;
                if (br == 0){
                    string tmp = decodeString(s.substr(st + 1, i - st - 1));
                    
                    if (cur == 0){
                        ans += tmp;
                    }else{
                        for (int j = 0; j < cur; ++ j){
                            ans += tmp;
                        }
                        cur = 0;
                    }
                }
            }else if (br == 0){
                if (ch < 'A'){
                    cur = cur * 10 + (ch - '0');
                }else{
                    ans += ch;
                }
            }
        }
        
        return ans;
    }
};