#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

#define mp make_pair
#define fi first
#define se second

int c, n;
unordered_set<string> ans;

vector<bool> sat;
vector<bool> rel;
vector< pair< vector<string>, string > > req;

int main(){
	scanf("%d", &c);
	cin.get();

	for (int i = 0; i < c; ++ i){
		string l;
		getline(cin, l);
		if (l[2] == ' '){
			vector<string> pre;
			int j = 2, k;
			bool r;

			do{
				k = l.find(' ', j + 1);
				string p = l.substr(j+1, k-j-1);
				pre.push_back(p);

				if (l[k+1] == 'a'){
					r = 1;
				}else if (l[k+1] == 'o'){
					r = 0;
				}else if (l[k+1] == 't'){
					k = l.find(' ', k + 1);
					p = l.substr(k+1);
					req.push_back(mp(pre, p));
					break;
				}

				j = l.find(' ', k + 1);
			}while(true);

			rel.push_back(r);
			sat.push_back(0);
		}else{
			ans.insert(l);
		}
	}

	n = req.size();
	/*
	for (int i = 0; i < n; ++ i){
		cout << req[i].se << ": " ;
		for (int j = 0; j < req[i].fi.size(); ++ j){
			cout << req[i].fi[j] << " ";
		}
		cout << "\n";
	}
	*/

	bool ch;
	do{
		ch = 0;
		// printf("==\n");

		for (int i = 0; i < n; ++ i){
			// printf("  %d\n", i);
			if (sat[i]) continue;

			bool s;
			if (rel[i]){
				s = 1;
				for (int j = 0; j < req[i].fi.size(); ++ j){
					// printf("    %d\n", j);
					if (! ans.count(req[i].fi[j])){
						s = 0;
						break;
					}
				}
			}else{
				s = 0;
				for (int j = 0; j < req[i].fi.size(); ++ j){
					// printf("    %d\n", j);
					if (ans.count(req[i].fi[j])){
						s = 1;
						break;
					}
				}
			}

			if (s){
				ans.insert(req[i].se);
				ch = 1;
				sat[i] = 1;
			}
		}
	}while (ch);

	printf("%lu\n", ans.size());

	return 0;
}