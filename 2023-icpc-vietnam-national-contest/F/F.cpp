#include <bits/stdc++.h>
using namespace std;

#define hi cerr << "HiHiHi\n";

#ifndef LOCAL
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e7 + 7;

struct Seg {
    array<int, 3> cnt;
    Seg() {
        for (int i = 0; i < 3; ++i) {
            cnt[i] = 0;
        }
    }
    friend Seg operator+(const Seg &lhs, const Seg &rhs) {
        Seg ans;
        for (int i = 0; i < 3; ++i) {
            ans.cnt[i] = lhs.cnt[i] + rhs.cnt[i];
        }
        return ans;
    }
};

struct SegTree {
    int n;
    vector<Seg> tree;
    SegTree() {}
    SegTree(int _n): n(_n) {
        tree.resize(n * 2);
    }
    void pull(int x) {
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
    }
    void add(int i, int ch, int val) {
        tree[i += n].cnt[ch] += val;
        for (i /= 2; i > 0; i /= 2) {
            pull(i);
        }
    }
    int query(int l, int r) {
        assert(l <= r);
        Seg res;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res = res + tree[l++];
            if (r & 1) res = res + tree[--r];
        }
        return max({res.cnt[0], res.cnt[1], res.cnt[2]});
    }
};

string foo = "RSP";

int idx(char ch) {
    return foo.find(ch);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        SegTree tree(n);
        for (int i = 0; i < n; ++i) {
            tree.add(i, idx(s[i]), 1);
        }
        int max_f = 0, res_k = -1;
        for (int k = 2; k <= n; ++k) {
            int cur = 0;
            for (int i = 0; i < n; i += k) {
                int l = i, r = min(i + k - 1, n - 1);
                cur += tree.query(l, r);
            }
            if (max_f <= cur) {
                max_f = cur;
                res_k = k;
            }
        }
        cout << res_k << '\n';
    }
    return 0;
}
