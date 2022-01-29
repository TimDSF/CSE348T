class NumArray {
public:
    int prefix[10005] = {0};
    NumArray(vector<int>& nums) {
        int n = nums.size();
        
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++ i){
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefix[right] : prefix[right] - prefix[left - 1];
    }
};