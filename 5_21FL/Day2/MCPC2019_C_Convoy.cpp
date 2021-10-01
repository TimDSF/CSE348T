// #include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
long long t[20005];

int main(){
	long long l, r, m;
	scanf("%d%d", &n, &k); // input n and k

	if (k > n) k = n; // if there are more cars than drivers
	for (int i = 0; i < n; i ++){ // input drivering times
		scanf("%lld", & t[i]);
	}
	sort(t,t+n); // sorting the time in asceding order
	
	//  using the 0 to k-1 drivers as they are the fastest
	l = t[0]; // left bound: the fastest driver has to reach ones
	r = 2 * t[k-1] * ((n+3)/4); // right bound: the slowest driver drives everyone

	while ( l < r ){ // binary search
		m = (l + r) / 2; // middle time inteval
		
		int total = 0; // number of people that can reach the stadium
		for (int i = 0; i < k; i ++){ // for each top k driver
			int tmp = ( m / t[i] + 1 ) / 2; // how many rounds it drives
			total += tmp * 4; // 4 people carried over per round
			if (m >= t[i]) total ++; // the driver themself
		}

		if ( total < n ){ // if we carried less than the number of people
			l = m + 1; // need to have more time
		}else{ // if we carried more than enough people
			r = m; // need no more time
		}
	}

	printf("%lld\n", l); // find the result at the left bound

	return 0;
}