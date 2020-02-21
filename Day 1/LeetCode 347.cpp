#include <map>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n=nums.	size(),i;
	vector<int> tops;
	unordered_map<int,int> freq;
	unordered_map<int,int>::iterator it;
	for (i=0;i<n;++i) ++freq[nums[i]];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > b;
	for (it=freq.begin();it!=freq.end();++it) b.push(make_pair(-it->second,it->first));
	for (i=0;i<k;++i) tops.push_back(b.top().second),b.pop();
//	return tops;
	for (i=0;i<tops.size();++i) printf("%d ",tops[i]);
	return 0;
}