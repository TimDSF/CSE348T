// Credit: Tim Dong
#include <cstdio>
#include <string>
#include <iostream>
#define MOD 998244353
using namespace std;

string L,U;
long long pow9[100005],sum9[100005],sumU,sumL;

long long  numBelow(string num){
	// long long sum = 1;
	// int i;

	// for (i=num.length()-1;i>=0;--i){
	// 	if (num[i]!='0') break;
	// }
	// sum = pow9[num.length()-i-1];
	
	// if (i==-1) return 0;

	// for (int j=1;j<i;++j){
	// 	if (num[j-1] == num[j]){
	// 		num[i] = '0';
	// 		return numBelow(num) % MOD;
	// 	}
	// }

	// if (i>0 && num[i-1]>=num[i]) sum *= num[i]-'0'; else sum *= num[i]-'0'-1;

	// if (i==0){
	// 	return (sum+sum9[num.length()-1]) % MOD;
	// }else{
	// 	num[i] = '0';
	// }
	// return (numBelow(num) + sum) % MOD;	

	long long sum = 0;
	int i,j;

	for (i=num.length()-1;i>=0;--i){
		if (num[i]!='0') break;
	}
	for (j=1;j<i;++j){
		if (num[j-1] == num[j]){
			num[i] = '0';
			break;
		}
	}
	i = j;

	while(true){
		// cout << num << ':' << sum << '\n';
		
		if (i==-1) break;

		if (i>0 && num[i-1]>=num[i]){
			sum += pow9[num.length()-i-1] * (num[i]-'0');
		}else{
			sum += pow9[num.length()-i-1] * (num[i]-'0'-1);
		}

		sum %= MOD;

		if (i==0){
			sum = (sum+sum9[num.length()-1]) % MOD;
			break;
		}else{
			num[i] = '0';
		}
		--i;
	}
	return sum;
}

int main(){
	cin >> L >> U;

	bool is = 1;
	for (int i=1;i<U.length();++i){
		if (U[i-1]==U[i]){
			is=0;
			break;
		}
	}

	pow9[0]=1;
	sum9[0]=0;
	for (int i=1;i<=U.length();++i){
		pow9[i] = (pow9[i-1]*9) % MOD;
		sum9[i] = (sum9[i-1] + pow9[i]) % MOD;
	}

	cout << (numBelow(U) + MOD - numBelow(L) + is) % MOD << "\n";
	return 0;
}