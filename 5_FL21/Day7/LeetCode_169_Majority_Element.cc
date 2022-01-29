class Solution {
public:
    int helper(vector<int>& nums, int l, int r){
        if (l == r) return nums[l];
        
        int m = (l+r)/2, c1 = helper(nums, l, m), c2 = helper(nums, m+1, r);
        if (c1 == c2) return c1;
        
        int ct1 = 0, ct2 = 0;
        for (int i = l; i <= r; ++ i){
            ct1 += nums[i] == c1;
            ct2 += nums[i] == c2;
        }
        
        return ct1 > ct2 ? c1 : c2;
    }
    
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), count = 0;
        return helper(nums, 0, n-1);
    }
}; 
/* Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), candidate = 0, count = 0;
        
        for (int i = 0; i < n; ++ i){
            if (count == 0){
                candidate = nums[i];
                count = 1;
            }else{
                count += (nums[i] == candidate) ? 1 : -1;
            }
        }
        
        return candidate;
    }
};
*/