class Solution {
public:
    int numSquares(int n) {
        int sqrt_n = (int) sqrt(n);
        vector<int> sqs = vector<int>(sqrt_n);
        for (int i = 0; i < sqrt_n; ++ i){
            sqs[i] = (i+1) * (i+1);
        }
        
        unordered_set<int> visited;
        queue< pair<int,int> > q; // pair<number, steps>
        q.push(make_pair(0, 0));
        
        while(!q.empty()){
            int num = q.front().first, steps = q.front().second + 1;
            q.pop();
            
            for (int i = sqrt_n - 1; i >= 0; -- i){
                int tmp = num + sqs[i];
                
                if (tmp == n){
                    return steps;
                }
                if (tmp < n && visited.count(tmp) == 0){
                    visited.insert(tmp);
                    q.push(make_pair(tmp, steps));
                }
            }
        }
        
        return -1;
    }
};