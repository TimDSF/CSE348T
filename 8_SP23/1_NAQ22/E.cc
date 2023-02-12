#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int n, m, cnt, ans;
char a[105][105];
bool v[105][105];
vector<pair<int,int>> p;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(){
	int i, j;
	scanf("%d%d", &n, &m);
	cin.get();
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			scanf("%c", &a[i][j]);
			if ('A' <= a[i][j] && a[i][j] <= 'W') {
				p.push_back({i, j});
			} else if (a[i][j] == '.') {
				++ cnt;
			}
		}
		cin.get();
	}

	for (int i = 0; i < p.size(); ++ i) {
		bool found = false;

		queue<pair<int,int>> q;
		q.push({p[i].first, p[i].second});
		v[p[i].first][p[i].second] = true;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int d = 0; d < 4; ++ d) {
				int xx = x + dx[d];
				int yy = y + dy[d];

				if ((a[xx][yy] == '.' || a[xx][yy] == ' ') && ! v[xx][yy]) {
					v[xx][yy] = true;
					q.push({xx, yy});
					if (a[xx][yy] == '.') {
						-- cnt;
						found = true;
					}
				}
			}
		}

		if (found) {
			++ ans;
		}
	}

	printf("%d %d\n", ans, cnt);

	return 0;
}