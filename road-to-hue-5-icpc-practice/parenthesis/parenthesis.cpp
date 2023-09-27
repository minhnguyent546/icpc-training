/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct Seg {
	int close, open;
	Seg(): close(0), open(0) {}
	Seg(char ch) {
		close = open = 0;
		if (ch == '(') {
			open = 1;
		}
		else if (ch == ')') {
			close = 1;
		}
		else assert(false);
	}
};

Seg operator+(const Seg &lhs, const Seg &rhs) {
	Seg ans;
	int new_match = min(lhs.open, rhs.close);
	ans.close = lhs.close + rhs.close - new_match;
	ans.open = rhs.open + lhs.open - new_match;
	return ans;
}

struct SegTree {
	int n;
	vector<Seg> tree;
	SegTree() {}
	SegTree(int _n): n(1) {
		while (n < _n) n <<= 1;
		tree.resize(n * 2);
	}
	void assign(int x, int l, int r, int i, char ch) {
		if (l == r) {
			assert(l == i);
			tree[x] = Seg(ch);
			return;
		}
		int mid = (l + r) >> 1;
		if (i <= mid) assign(x * 2, l, mid, i, ch);
		else assign(x * 2 + 1, mid + 1, r, i, ch);
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
	}
	Seg query(int x, int l, int r, int u, int v) {
		if (r < u || l > v) return Seg{};
		if (u <= l && r <= v) return tree[x];
		int mid = (l + r) >> 1;
		Seg left = query(x * 2, l, mid, u, v);
		Seg right = query(x * 2 + 1, mid + 1, r, u, v);
		return left + right;
	}

};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegTree tree(n);
    for (int i = 0; i < n; ++i) {
    	tree.assign(1, 0, n - 1, i, s[i]);
    }
    for (int k = 0; k < q; ++k) {
    	int op, l, r;
    	cin >> op >> l >> r;
    	--l; --r;
    	if (op == 1) {
    		swap(s[l], s[r]);
    		tree.assign(1, 0, n - 1, l, s[l]);
    		tree.assign(1, 0, n - 1, r, s[r]);
    	}
    	else if (op == 2) {
    		auto res = tree.query(1, 0, n - 1, l, r);
    		cout << (res.close == 0 && res.open == 0 ? "Yes\n" : "No\n");
    	}
    }
	return 0;
}
