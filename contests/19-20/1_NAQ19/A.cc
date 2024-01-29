#include <stack>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int n,l;
string e;
bool a[30];
int main(){
	int i;
	char c;
	bool t1,t2;
	stack<bool> s;
	cin>>n;
	for (i=0;i<n;i++){
		cin>>c;
		a[i]=c=='T';
	}
	cin.get();
	getline(cin,e);
	l=e.length();
	for (i=0;i<l;i+=2){
		c=e[i];
		if (c=='*'){
			t1=s.top();
			s.pop();
			t2=s.top();
			s.pop();
			s.push(t1&&t2);
		}else if (c=='+'){
			t1=s.top();
			s.pop();
			t2=s.top();
			s.pop();
			s.push(t1||t2);
		}else if (c=='-'){
			t1=s.top();
			s.pop();
			s.push(!t1);
		}else{
			s.push(a[c-'A']);
		}
	}
	printf("%c\n",s.top()?'T':'F');
	return 0;
}