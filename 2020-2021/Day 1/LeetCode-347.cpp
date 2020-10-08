class Solution { // 20ms, runtime: faster than 99.96%
public: // this is an example of how not to write code that is easy to read
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size(),i;
        vector<int> tops;
        unordered_map<int,int> freq;
        unordered_map<int,int>::iterator it;
        for (i=0;i<n;++i) ++freq[nums[i]];
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > b;
        for (it=freq.begin();it!=freq.end();++it) b.push(make_pair(-it->second,it->first));
        for (i=0;i<k;++i) tops.push_back(b.top().second),b.pop();
        return tops;
    }
};