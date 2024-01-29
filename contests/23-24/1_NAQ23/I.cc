#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define N 100005
using namespace std;

int T;
int len[N];

int find_len(int i) {
	int l = 0;
	while (i) {
		++ l;
		i /= 10;
	}
	return l;
}

int main() {
	for (int i = 1; i < N; ++ i) {
		len[i] = find_len(i);
	}
	scanf("%d", &T);

	for (int t = 0; t < T; ++ t) {
		string s;
		cin >> s;

		int st = 0;
		set<int> eats;
		for (int i = 0; i < 5; ++ i) {
			st = st * 10 + s[i] - '0';

			int j, n, eat = -1;
			// printf("=> %d\n", st);
			for (j = i + 1, n = st + 1; j < s.length(); j += len[n++]) {
				if (n > 99999) break;
				if (s[j] == '0') break;

				int next = stoi(s.substr(j, len[n]));
				// printf(" -> A %d %d\n", n, next);
				if (next == n) {
					continue;
				} 

				if (eat != -1) break;

				next = stoi(s.substr(j, len[n + 1]));
				// printf(" -> B %d %d\n", n + 1, next);
				if (next == n + 1) {
					eat = n;
					++n;
					continue;
				}

				break;
			}

			if (j == s.length()) {
				if (eat == -1) {
					if (st > 1) eats.insert(st - 1);
					if (n <= 99999) eats.insert(n);
				} else {
					eats.insert(eat);
				}
			}
		}

		printf("%zu\n", eats.size());
		for (const int eat : eats) printf("%d ", eat); printf("\n");
	}

	return 0;
}