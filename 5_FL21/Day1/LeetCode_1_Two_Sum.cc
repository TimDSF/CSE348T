class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> indices; // maps nums[i] --> i
        vector<int> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; ++ i){
            int remainder = target - nums[i];
            
            if (indices.count(remainder)){
                ans = {indices[remainder],i};
            }else{
                indices[nums[i]] = i;
            }
        }
        
        return ans;
    }
};

