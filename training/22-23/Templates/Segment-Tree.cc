#include <cstdio>
#include <vector>
using namespace std;

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

int main(){
	scanf("%d", &n);
	vector<int> arr(n);
	seg.resize(n << 2);
	tag.resize(n << 2);
	
	for (int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	build(arr, seg, tag, 0, n, 1);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum(seg, tag, l, r + 1, 0, n, 1));
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		update(seg, tag, l, r + 1, d, 0, n, 1);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum(seg, tag, l, r + 1, 0, n, 1));
	}

	return 0;
}