#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>
#include <unordered_map>
using namespace std;

typedef struct Node{
	int idx;
	int cbc;  // closest black child
	Node * parent;
	vector<Node *> children;
	Node(int i, int c, Node * p) : idx(i), cbc(c), parent(p) {}
} Node;

int c[200005];
bool visited[200005];
int ans;

void build(int rt, Node * root, const vector<vector<int>>& e, unordered_map<int, Node *>& mp) {
	for (int v : e[rt]) {
		if (!visited[v]) {
			Node * child = new Node(v, 0x3fffffff, root);
			mp[v] = child;
			root->children.push_back(child);
			visited[v] = true;
			build(v, child, e, mp);
		}
	}
}

void test(Node * root) {
	printf("%d: ", root->idx);
	for (Node * child : root->children) {
		printf("%d ", child->idx);
	}
	printf("\n");
	for (Node * child : root->children) {
		test(child);
	}
}

void update(Node * node) {
	int steps = 0;

	ans = min(node->cbc, ans);
	node->cbc = 0;

	while (node->parent != NULL) {
		node = node->parent;
		++steps;

		ans = min(steps + node->cbc, ans);
		if (node->cbc < steps) {
			return;
		} else {
			node->cbc = steps;
		}
		if (steps > ans) return;
	}
}

void solve() {
	int n, u, v, rt;
	Node * root;
	scanf("%d", &n);
	rt = rand() % n + 1;

	vector<vector<int>> e(n+1, vector<int>());
	unordered_map<int, Node *> mp;
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; ++ i) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i < n; ++ i) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	root = new Node(rt, 0x3fffffff, NULL);
	mp[rt] = root;
	visited[rt] = true;
	build(rt, root, e, mp);

	// test(root);

	ans = 0x3fffffff;

	update(mp[c[0]]);
	for (int i = 1; i < n; ++ i) {
		update(mp[c[i]]);
		printf("%d ", ans);
	}
	printf("\n");
}

int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) solve();
	return 0;
}