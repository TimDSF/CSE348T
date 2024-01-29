#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
#define N 1000006
#define EPS 0.0000000001L
using namespace std;

int n, k;
int q[N], f[N];

/*
 * Priority Queue, O(n * log n), TLE: 10/20
**/
bool test1(long double m) {
	priority_queue<
		pair<int, long double>, 
		vector<pair<int, long double>>, 
		greater<pair<int, long double>>
	> foods;  // <date, amount> 

	for (int i = 1; i <= n; ++ i) {
		if (q[i]) foods.push({f[i], q[i]});

		while (foods.top().first < i) foods.pop();

		long double need = m;
		while (!foods.empty() && need > EPS) {
			if (foods.top().second > need) {
				need = 0;

				const pair<int, long double> tmp{foods.top().first, foods.top().second - need};
				foods.pop();				
				foods.push(tmp);
				break;
			} else {
				need -= foods.top().second;
				foods.pop();				
			}
		}

		if (need > EPS) return false;

	}

	return true;
}

/*
 * O(n), correct
**/
bool fail() {
	int last = 0;

	for (int i = 1; i <= n; ++ i) {
		if (q[i]) last = max(last, f[i]);
	
		if (last < i) return true;
	}
	
	return false;
}


/*
 * Greedy, O(n), WA: 12/20
**/
long double bit[N];

void update(int n, long double d) {
	for (int i = n; i <= N; i += (i) & (-i)) {
		bit[i] += d;
	}
}

long double query(int n) {
	long double ans = 0;
	for (int i = n; i > 0; i -= (i) & (-i)) {
		ans += bit[i];
	}
	return ans;
}

void push(int n, long double d) {
	update(N - n, d);
}


long double pop(int n) {
	return query(N - n);
}

bool test2(long double m) {
	memset(bit, 0, sizeof(bit));

	int day = 1; long double needs = m;

	for (int i = 1; i <= n; ++ i) {
		push(i, q[i]);
		// push(f[i], -q[i]);  // TODO: This is not correct, to push expiration

		long double have = pop(day);
		while (have > 0) {
			if (needs > have) {
				needs -= have;
				push(i, -have); have = 0;
			} else {
				push(i, -needs); have -= needs;
				++ day; needs = m;
			}
		}

		if (day <= i) return false;
		if (day > n) return true;
	}

	return true;
}


/*
 * Reverse Map, does not help
**/
int mp[N];  // map the index from i to j, i: sorted by start, j: sorted by end

void gen_mp() {
	struct P { int lo; int hi; };
	vector<P> v;
	for (int i = 1; i <= n; ++ i) v.push_back({i, f[i]});
	sort(v.begin(), v.end(), [](P a, P b) { return a.hi < b.hi; });
	for (int i = 0; i < n; ++ i) mp[v[i].lo] = i + 1;
}

bool test3(long double m) {
	vector<int> foods(N, 0);
	int idx = 0;

	for (int i = 1; i <= n; ++ i) {
		foods[mp[i]]
	}

	return true;
}


int main() {
/*
	freopen("c.in", "w", stdout);
	printf("1000000 39\n1 1000000\n");
	for (int i = 2; i <= 1000000; ++ i) printf("1 %d\n", i);
	return 0;
// */

	scanf("%d%d", &n, &k);

	long double lo = 0, hi = 0;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &q[i], &f[i]);
		hi = hi + q[i];
	}
	hi /= n;

	gen_mp();

	if (fail()) {
		printf("-1\n");
		return 0;
	}

	while (hi - lo > EPS) {
		long double m = (lo + hi) / 2;
		printf("%.9Lf %.9Lf %.9Lf\n", lo, m, hi);

		if (test3(m)) {
			lo = m;
			printf(" +\n");
		} else {
			hi = m;
			printf(" -\n");
		}
	}

	printf("%.15Lf\n", (long double) lo / k);
// 
	return 0;
}