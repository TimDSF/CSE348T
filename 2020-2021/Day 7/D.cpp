#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,d,a[100];
int pH[10005];
vector<int> occ[10005];
unordered_map<int,int> mp;

pair<int,int> mx[40005];

int search(int i,int p, bool left){ // left: whether returning the left indices
	int l = 0, r = occ[p].size()-1, m;
	while(l<=r){
		m = (l+r)/2;
		if (occ[p][m]<i){
			l=m+1;
		}else if (i<occ[p][m]){
			r=m-1;
		}else{
			return m;
		}
	}
	return left ? l : r;
}

int num(int l,int r,int p){ // [ , ]
	return search(r,p,false)-search(l,p,true)+1;
}

void build(int l,int r,int i){ // [ , )
	if (l+1==r){
		mx[i].first = pH[l];
		mx[i].second = -1;
		return;
	}

	int m=(l+r)/2;

	build(l,m,i*2); build(m,r,i*2+1);

	unordered_set<int> c;

	c.insert(mx[i*2].first);
	c.insert(mx[i*2].second);
	c.insert(mx[i*2+1].first);
	c.insert(mx[i*2+1].second);

	mx[i].first=-1; mx[i].second=-1;

	for (unordered_set<int>::iterator it=c.begin();it!=c.end();++it){
		if (*it == -1) continue;
		if ( num(l,r-1,*it) < (r-l+1)/2 ) continue;
		if (mx[i].first == -1) mx[i].first = *it; else mx[i].second = *it;
	}
}

pair<int,int> query(int fm,int to,int l,int r,int i){
	if (fm<=l && r<=to) return mx[i];

	int m = (l+r)/2;

	pair<int,int> tmp;
	unordered_set<int> c;

	if (fm < m){
		tmp=query(fm,to,l,m,i*2);
		c.insert(tmp.first); c.insert(tmp.second);
	}
	if (m < to){
		tmp=query(fm,to,m,r,i*2+1);
		c.insert(tmp.first); c.insert(tmp.second);
	}

	tmp.first=-1; tmp.second=-1;
	
	int ll = max(l,fm), rr = min(r,to);

	for (unordered_set<int>::iterator it=c.begin();it!=c.end();++it){
		if (*it == -1) continue;
		if ( num(ll,rr-1,*it) < (rr-ll+1)/2 ) continue;
		if (tmp.first==-1) tmp.first=*it; else tmp.second=*it;
	}

	return tmp;
}

int main(){
	int i,l,r,pH_int;
	double pH_double;
	pair<int,int> tmp;
	
	scanf("%d%d",&n,&m);

	// Discretification of pH[]
	for (i=0;i<n;++i){
		scanf("%lf",&pH_double);
		pH_int = pH_double*1000000;
		if (mp.find(pH_int) == mp.end()){
			mp[pH_int] = d;
			++ d;
		}
		pH[i] = mp[pH_int];
		occ[pH[i]].push_back(i);
	}

	build(0,n,1);

	for (i=0;i<m;++i){
		scanf("%d%d",&l,&r);
		--l;--r;
		tmp = query(l,r+1,0,n,1);
		if (tmp.first != -1 && num(l,r,tmp.first) > (r-l+1)/2 || tmp.second! = -1 && num(l,r,tmp.second) > (r-l+1)/2){
			printf("usable\n");
		}else{
			printf("unusable\n");
		}
	}
	return 0;


	return 0;
}