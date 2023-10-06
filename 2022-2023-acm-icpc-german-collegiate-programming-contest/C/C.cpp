/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct FT {
    int n;
    vector<int> tree;
    FT() {}
    FT(int _n): n(_n) {
        tree.resize(n);
    }
    void add(int i, int val) {
        while (i < n) {
            tree[i] += val;
            i |= (i + 1);
        }
    }
    int query(int i) {
        int res{};
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    FT tree(n);
    for (int w = 0; w < q; ++w) {
        char op;
        int a, b;
        cin >> op >> a;
        if (op == '?') cin >> b;
        --a; --b;
        if (op == '-') {
            tree.add(a, 1);
        } else if (op == '+') {
            tree.add(a, -1);
        } else if (op == '?') {
            if (a > b) swap(a, b);
            int x = tree.query(a, b);
            int y = tree.query(b, n - 1) + tree.query(0, a);
            if (x == 0 || y == 0) {
                cout << "possible\n";
            }
            else {
                cout << "impossible\n";
            }
        } else assert(false);
    }

	return 0;
}
