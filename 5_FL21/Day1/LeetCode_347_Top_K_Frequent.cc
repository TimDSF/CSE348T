class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> ans;
        unordered_map<int, int> freq;
        priority_queue< pair<int, int>> tops;
        
        for (int i = 0; i < n; ++ i){
            ++freq[nums[i]];
        }
        
        // unordered_map<int, int>::iterator it;
        for (auto it = freq.begin(); it != freq.end(); ++ it){
            tops.push(make_pair(- it -> second, it -> first));
            if (tops.size() > k) tops.pop();
        }
        
        for (int i = 0; i < k; ++ i){
            ans.push_back(tops.top().second);
            tops.pop();
        }
        
        return ans;
    }
};