class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // ans: answer, n: size of the nums array
        int ans, n = nums.size();
        
        // dp: dp array
        vector<int> dp(n, 0);
        
        // base case
        dp[0] = nums[0];
        ans = dp[0];
        
        for (int i = 1; i < n; ++ i){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};