class NumArray {
private:
    int bit[30001] = {0}, n;
    vector<int> nums;
    
    void _update(int i, int val){
        for ( ;i <= n; i += i & (-i)){
            bit[i] += val;
        }
    }
    
    int _sum(int i){
        int ans = 0;
        for (; i; i -= i & (-i)){
            ans += bit[i];
        }
        return ans;
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        
        for (int i = 0; i < n; ++ i){
            _update(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        _update(i + 1, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int l, int r) {
        return _sum(r + 1) - _sum(l);
    }
};