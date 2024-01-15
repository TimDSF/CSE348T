【动态规划】
类型：
	背包DP
	区间DP
	环形DP
	树形DP
	状压DP
	数位DP
	轮廓DP
	概率DP
优化：
	矩阵乘法
	单调队列
	鞋履优化
	四边形不等式（区间DP）: 
		区间包含单调性
		四边形不等式: w(l1, r1) + w(l2, r2) <= w(l1, r2) + w(l2, r1)
		那么：argmin(l, r - 1) <= argmin(l, r) <= argmin(l + 1, r)
		所以：O(n ^ 3) => O(n ^ 2)

【树论】
树的直径
树的重心
最近公共祖先
树链剖分

【图论】
拓扑排序 (Kahn)
有向无环图最短路径
最小生成树 (Kruskal)
多源最短路径 (Floyd)
单源最短路径 (Dijkstra, 没有负边)
单源最短路径 (SPFA, 没有负环)
最小环
强连通分量
2-SAT
网络流 (Ford-Fulkerson)
网络流 (Dinic, O(E min{E^1/2, V^2/3}))

【数据结构】
线段树
ST表

【计算几何】
凸包

=================================================

【树论】
树的直径
const int N = 10000 + 10;
int n, c, d[N];
vector<int> E[N];
void dfs(int u, int fa) {
  for (int v : E[u]) {
    if (v == fa) continue;
    d[v] = d[u] + 1;
    if (d[v] > d[c]) c = v;
    dfs(v, u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    E[u].push_back(v), E[v].push_back(u);
  }
  dfs(1, 0);
  d[c] = 0, dfs(c, 0);
  printf("%d\n", d[c]);
  return 0;
}

树的重心
// 这份代码默认节点编号从 1 开始，即 i ∈ [1,n]
int size[MAXN],  // 这个节点的“大小”（所有子树上节点数 + 该节点）
    weight[MAXN],  // 这个节点的“重量”
    centroid[2];   // 用于记录树的重心（存的是节点编号）
void GetCentroid(int cur, int fa) {  // cur 表示当前节点 (current)
  size[cur] = 1;
  weight[cur] = 0;
  for (int i = head[cur]; i != -1; i = e[i].nxt) {
    if (e[i].to != fa) {  // e[i].to 表示这条有向边所通向的节点。
      GetCentroid(e[i].to, cur);
      size[cur] += size[e[i].to];
      weight[cur] = max(weight[cur], size[e[i].to]);
    }
  }
  weight[cur] = max(weight[cur], n - size[cur]);
  if (weight[cur] <= n / 2) {  // 依照树的重心的定义统计
    centroid[centroid[0] != 0] = cur;
  }
}

最近公共祖先
int n, t = 0, l;
vector<int> t1, t2; 
vector<vector<int>> e, up;
void dfs(int u, int rt) {
	t1[u] = ++ t;
	up[u][0] = rt;
	for (int i = 1; i <= l; ++ i) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	for (int v : e[u]) {
		if (v == rt) continue;
		dfs(v, u);
	}
	t2[u] = ++ t;
}
inline bool is_ancester(const int u, const int v) {
	return t1[u] <= t1[v] && t2[u] >= t2[v];
}
int lca(int u, int v) {
	if (is_ancester(u, v)) return u;
	if (is_ancester(v, u)) return v;
	for (int i = l; i >= 0; -- i) {
		if (!is_ancester(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}
int main() {
	scanf("%d", &n);
	l = ceil(log2(n));
	t1.resize(n); t2.resize(n);
	e.assign(n, vector<int>());
	up.assign(n, vector<int>(l + 1));
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
	}
	dfs(0, 0);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < l; ++ j) {
			printf("%d ", up[i][j]);
		}
		printf("\n");
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}

树链剖分
int n, ln;

vector<vector<int>> edges;
vector<int> parent;
vector<int> hchild;

vector<vector<int>> hpaths;
vector<int> htop;
vector<int> pid;
vector<int> pidx;
vector<vector<int>> ledges;
int dfs(int u) {
	int size = 1;
	int max_size = 0;
	for (int v : edges[u]) {
		if (v == parent[u]) continue;
		parent[v] = u;
		int c_size = dfs(v);
		if (c_size > max_size) {
			max_size = c_size;
			hchild[u] = v; 
		}
		size += c_size;
	}
	return size;
}

void decomp(int u, int h) {
	if (h == u) {
		pid[u] = hpaths.size();
		pidx[u] = 0;
		hpaths.push_back(vector<int>{u});
	} else {
		pid[u] = pid[h];
		pidx[u] = pidx[h] + 1;
		hpaths[pid[u]].push_back(u);
	}
	for (int v : edges[u]) {
		if (v == parent[u]) continue;
		if (v == hchild[u]) {
			htop[v] = hpaths[pid[u]][0];
			decomp(v, u);
		} else {
			ledges.push_back(vector<int>());
			ledges[pid[u]].push_back(hpaths.size());
			htop[v] = u;
			decomp(v, v);
		}
	}
}

int main() {
	scanf("%d", &n);

	edges.assign(n, vector<int>());
	parent.resize(n);
	hchild.resize(n);
	htop.resize(n);
	pid.resize(n);
	pidx.resize(n);
	ledges.assign(1, vector<int>());

	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(0);
	decomp(0, 0);

	printf("\nHeavy Chains:\n");
	for (int i = 0; i < hpaths.size(); ++ i) {
		printf("%d: ", i);
		for (int u : hpaths[i]) {
			printf("%d ", u);
		}
		printf("\n");
	}
	printf("\nNode\tChain\tIndex\thtop\n");

	for (int i = 0; i < n; ++ i) {
		printf("%d\t%d\t%d\t%d\n", i, pid[i], pidx[i], htop[i]);
	}

	printf("\nLight Edges:\n");
	for (int i = 0; i < ledges.size(); ++ i) {
		printf("%d: ", i);
		for (int j = 0; j < ledges[i].size(); ++ j) {
			printf("%d ", ledges[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

【图论】
拓扑排序 (Kahn)
void toposort() {
  queue<int> S;
  vector<int> L;  // 结果
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      in[e[i][j].v]++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (in[i] == 0) S.push(i);
  while (!S.empty()) {
    int u = S.front();
    S.pop();
    L.push_back(u);
    for (int i = 0; i < e[u].size(); i++) {
      if (--in[e[u][i].v] == 0) {
        S.push(e[u][i].v);
      }
    }
  }
}

有向无环图最短路径
void dp(int s) {  // 以 s 为起点求单源最长（短）路
  toposort();     // 先进行拓扑排序
  memset(min_dis, 0x3f, sizeof(min_dis));
  memset(max_dis, 0, sizeof(max_dis));
  min_dis[s] = 0;
  for (int i = 0; i < L.size(); i++) {
    int u = L[i];
    for (int j = 0; j < e[u].size(); j++) {
      min_dis[e[u][j].v] = min(min_dis[e[u][j].v], min_dis[u] + e[u][j].w);
      max_dis[e[u][j].v] = max(max_dis[e[u][j].v], max_dis[u] + e[u][j].w);
    }
  }
}

最小生成树 (Kruskal)
int n, m;
priority_queue<pair<int,pair<int,int>>, 
	vector<pair<int,pair<int,int>>>, 
	greater<pair<int,pair<int,int>>>> edges;
vector<vector<pair<int,int>>> te;  // minimum spanning tree edges
vector<int> fa;  // disjoint union
int get_fa(int u) {
	if (fa[u] == u) return u;
	return fa[u] = get_fa(fa[u]);
}
int main() {
	scanf("%d%d", &n, &m);
	te.assign(n, vector<pair<int,int>>());
	fa.resize(n);
	for (int i = 0; i < n; ++ i) {
		fa[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges.push({w, {u, v}});
	}
	int found = 0;
	while (found < n - 1) {
		int w = edges.top().first;
		int u = edges.top().second.first;
		int v = edges.top().second.second;
		printf("%d-%d : %d\n", u, v, w);
		edges.pop();
		if (get_fa(u) != get_fa(v)) {
			fa[fa[v]] = fa[fa[v]];
			te[u].push_back({v, w});
			te[v].push_back({u, w});
			printf("  yes\n");
			++found;
		} 
	}
	for (int i = 0; i < n; ++i) {
		printf("%d: ", i);
		for (int j = 0; j < te[i].size(); ++j) {
			printf("%d(%d) ", te[i][j].first, te[i][j].second);
		}
		printf("\n");
	}
}

多源最短路径 (Floyd)
int f[X][Y];
for (k = 1; k <= n; k++) {
  for (x = 1; x <= n; x++) {
    for (y = 1; y <= n; y++) {
      f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
    }
  }
}

单源最短路径 (Dijkstra, 没有负边)
struct edge {
  int v, w;
};
struct node {
  int dis, u;
  bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

单源最短路径 (SPFA, 没有负环)
struct edge {
  int v, w;
};

vector<edge> e[maxn];
int dis[maxn], cnt[maxn], vis[maxn];
queue<int> q;

bool spfa(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;  // 记录最短路经过的边数
        if (cnt[v] >= n) return false;
        // 在不经过负环的情况下，最短路至多经过 n - 1 条边
        // 因此如果经过了多于 n 条边，一定说明经过了负环
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return true;
}

最小环
// 删掉每一条边，然后Dijkstra

强连通分量
// g 是原图，g2 是反图
void dfs1(int u) {
  vis[u] = true;
  for (int v : g[u])
    if (!vis[v]) dfs1(v);
  s.push_back(u);
}
void dfs2(int u) {
  color[u] = sccCnt;
  for (int v : g2[u])
    if (!color[v]) dfs2(v);
}
void kosaraju() {
  sccCnt = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs1(i);
  for (int i = n; i >= 1; --i)
    if (!color[s[i]]) {
      ++sccCnt;
      dfs2(s[i]);
    }
}

2-SAT
Implication Grpah: (A or B) <=> (-A => B) and (-B => A)
SCC: solution <=> a and -a in different SCC
Solution: toposort
int n;
vector<vector<int>> adj, adj_t;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;
void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}
void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}
bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }
    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }
    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}
void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated 
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

网络流 (Ford-Fulkerson)
#define INF 0x7fffffff
#define S 0
#define T (n - 1)

int n, m;
vector<int> e[100000];
unordered_map<int, int> c;
inline int ha(const int u, const int v) {
	return (u << 15) + v;
}
int bfs(const int s, const int t, vector<int>& fa) {
	fill(fa.begin(), fa.end(), -1);
	fa[s] = s;
	queue<pair<int,int>> q;
	q.push({s, INF});
	while (!q.empty()) {
		int u = q.front().first;
		int f = q.front().second;
		q.pop();

		for (int v : e[u]) {
			if (fa[v] == -1 && c.at(ha(u, v))) {
				fa[v] = u;
				int ff = min(f, c.at(ha(u, v)));
				if (v == t) {
					return ff;
				}
				q.push({v, ff});
			}
		}
	}
	return 0;
}
int main() {
	int max_flow = 0;
	scanf("%d%d", &n, &m);
	vector<int> fa(n);
	for (int i = 0; i < m; ++ i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(v);
		c[ha(u, v)] = w;
	}
	while (int new_flow = bfs(S, T, fa)) {
		max_flow += new_flow;
		int v = T;
		while (v != S) {
			int u = fa[v];
			c[ha(u, v)] -= new_flow;
			c[ha(v, u)] += new_flow;
			v = u;
		}
	}
	printf("max_flow: %d\n", max_flow);
}

网络流 (Dinic, O(E min{E^1/2, V^2/3}))
struct MF {
  struct edge {
    int v, nxt, cap, flow;
  } e[N];

  int fir[N], cnt = 0;
  int n, S, T;
  ll maxflow = 0;
  int dep[N], cur[N];
  void init() {
    memset(fir, -1, sizeof fir);
    cnt = 0;
  }
  void addedge(int u, int v, int w) {
    e[cnt] = {v, fir[u], w, 0};
    fir[u] = cnt++;
    e[cnt] = {u, fir[v], 0, 0};
    fir[v] = cnt++;
  }
  bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * (n + 1));

    dep[S] = 1;
    q.push(S);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = fir[u]; ~i; i = e[i].nxt) {
        int v = e[i].v;
        if ((!dep[v]) && (e[i].cap > e[i].flow)) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[T];
  }
  int dfs(int u, int flow) {
    if ((u == T) || (!flow)) return flow;
    int ret = 0;
    for (int& i = cur[u]; ~i; i = e[i].nxt) {
      int v = e[i].v, d;
      if ((dep[v] == dep[u] + 1) &&
          (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
        ret += d;
        e[i].flow += d;
        e[i ^ 1].flow -= d;
        if (ret == flow) return ret;
      }
    }
    return ret;
  }
  void dinic() {
    while (bfs()) {
      memcpy(cur, fir, sizeof(int) * (n + 1));
      maxflow += dfs(S, INF);
    }
  }
} mf;

【字符串】
字符串哈希
	primes: 1000000007 and 1000000009


【数据结构】
线段树
int n, m;
vector<int> seg, tag; 

void build(const vector<int>& arr, vector<int>& seg, vector<int>& tag, int L, int R, int i){
	if (L + 1 >= R){
		seg[i] = arr[L];
		return;
	}
	int M = (L + R) / 2;
	build(arr, seg, tag, L, M, i * 2);
	build(arr, seg, tag, M, R, i * 2 + 1);
	seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

int sum(vector<int>& seg, vector<int>& tag, int l, int r, int L, int R, int i){
	if (l <= L && R <= r) return seg[i];
	int M = (L + R) / 2, ans = 0;
	if (tag[i]){
		seg[i * 2] += tag[i] * (M - L); tag[i * 2] += tag[i];
		seg[i * 2 + 1] += tag[i] * (R - M); tag[i * 2 + 1] += tag[i];
		tag[i] = 0;
	}
	if (L < r && l < M) ans += sum(seg, tag, l, r, L, M, i * 2);
	if (M < r && l < R) ans += sum(seg, tag, l, r, M, R, i * 2 + 1);
	return ans;
}

// calculate: seg of [fm,to)
// current node: s[i] of seg [l,r)
void update(vector<int>& seg, vector<int>& tag, int l, int r, int dl, int L, int R, int i){
	if (l <= L && R <= r){
		seg[i] += dl * (R - L); tag[i] += dl;
		return;
	}
	int M = (L + R) / 2;
	if (tag[i]){
		seg[i * 2] += tag[i] * (M - L); tag[i * 2] += tag[i];
		seg[i * 2 + 1] += tag[i] * (R - M); tag[i * 2 + 1] += tag[i];
		tag[i] = 0;
	}
	if (L < r && l < M) update(seg, tag, l, r, dl, L, M, i * 2);
	if (M < r && l < R) update(seg, tag, l, r, dl, M, R, i * 2 + 1);
	seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

ST表
int n, m, lg;
vector<int> a;
vector<vector<int>> st;
vector<int> log2n;

int main() {
	scanf("%d", &n);
	a.resize(n);
	log2n.resize(n + 1);
	log2n[1] = 0; log2n[2] = 1;
	for (int i = 3; i <= n; ++ i) {
		log2n[i] = log2n[i / 2] + 1;
	}

	lg = ceil(log2(n));
	st.assign(n, vector<int>(lg + 1));

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		st[i][0] = a[i];
	}
	for (int j = 1; j <= lg; ++ j) {
		for (int i = 0; i + (1 << j) - 1 < n; ++ i) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		int lg = log2n[r - l + 1];
		int mx = max(st[l][lg], st[r - (1 << lg) + 1][lg]);
		printf("%d\n", mx);
	}
}

【计算几何】
凸包
struct Point {
	int x, y;
	Point() : x(0), y(0) {};
	Point(int xx, int yy) : x(xx), y(yy) {};
};

Point c0[N], c1[N];

double dist(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int ccw(Point p1, Point p2, Point p3) {
	int xx0 = p2.x - p1.x, yy0 = p2.y - p1.y;
	int xx1 = p3.x - p2.x, yy1 = p3.y - p2.y;
	return xx0 * yy1 - xx1 * yy0 > 0;
}

int cw(Point p1, Point p2, Point p3) {
	int xx0 = p2.x - p1.x, yy0 = p2.y - p1.y;
	int xx1 = p3.x - p2.x, yy1 = p3.y - p2.y;
	return xx0 * yy1 - xx1 * yy0 < 0;
}

bool cmp(Point p1, Point p2) {
	return p1.x < p2.x;
}

int main(){
	int n, m0, m1;
	Point p0 = Point(1005, 0), p1 = Point(-1005, 0);

	vector<Point> ps;
	unordered_set<int> pos;

	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		int x, y;
		scanf("%d%d", &x, &y);
		pos.insert((x + 1000) * 10000 + (y + 1000));

	}
	for (int p : pos) {
		int x = p / 10000 - 1000;
		int y = p % 10000 - 1000;
		ps.push_back(Point(x,y));
		if (x < p0.x) {
			p0.x = x; p0.y = y;
		}
		if (x > p1.x) {
			p1.x = x; p1.y = y;
		}
	}

	sort(ps.begin(), ps.end(), cmp);
	c0[0] = p0; m0 = 1; 
	c1[0] = p0; m1 = 1;

	for (int i = 1; i < ps.size(); ++ i) {
		while (m0 >= 2 && !ccw(c0[m0 - 2], c0[m0 - 1], ps[i])) {
			-- m0;
		}
		c0[m0] = ps[i]; ++ m0;

		while (m1 >= 2 && !cw(c1[m1 - 2], c1[m1 - 1], ps[i])) {
			-- m1;
		}
		c1[m1] = ps[i]; ++ m1;
	}

	for (int i = m1 - 2; i > 0; -- i) {
		c0[m0 ++] = c1[i];
	}

	double ans = 0;
	for (int i = 0; i < m0; ++ i) {  // delta: i
		int l = 1, r = m0 - 1;
		double d = 0;
		while (l <= r) {
			int m1 = (l + r) / 2;
			double d1 = dist(c0[i], c0[(m1 + i) % m0]);
			d = max(d, d1);
			if (m1 == l) {
				++ l;
			} else if (m1 == r) {
				-- r;
			} else {
				int m2 = m1 + 1;
				double d2 = dist(c0[i], c0[(m2 + i) % m0]);
				if (d1 < d2) {
					l = m1 + 1;
				} else {
					r = m1 - 1;
				}
			}
		}
		ans = max(ans, d);
	}

	printf("%lf\n", ans);

	return 0;
}