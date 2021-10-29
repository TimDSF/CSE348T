class Solution {
public:
    int numSquares(int n) {
        // calculate sqrt(n)
        int sqrt_n = sqrt(n);
        
        // initialize the dp array of size n, 0 valued.
        int dp[10001]; // dp[i]: the minimum number of squares required to sum up to i
        memset(dp, 0x7f, sizeof(dp)); // initialize all entries to infinity, 0x7f7f7f7f
        dp[0] = 0; // base case: dp[0] = 0
        
        // initalize the array of squares
        int sq[100];
        
        for (int i = 1; i <= sqrt_n; ++ i){
            sq[i-1] = i * i;
        }
        
        // dynamic programming
        for (int i = 0; i < n; ++ i){ // for each value we have achieved optimial
            for (int j = 0; j < sqrt_n; ++ j){ // tries to improve future ones
                int k = i + sq[j];
                if (k > n) break;
                
                dp[k] = min(dp[k], dp[i] + 1);
            }
        }
        
        return dp[n];
    }
};