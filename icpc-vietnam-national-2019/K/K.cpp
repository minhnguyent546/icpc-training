/**            
 * author      minhnguyent546
 * created_at  Thursday, 2023-09-14 21:47:17
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

vector<int> vals;

struct Seg {
    int min, cnt;
    int odd, even;
    Seg(int _min = INF, int _cnt = 0, int _odd = 0, int _even = 0):
        min(_min), cnt(_cnt), odd(_odd), even(_even) {}

    void add(int amt) {
        min += amt;
        if (amt & 1) swap(odd, even);
    }

};

Seg operator+(const Seg &lhs, const Seg &rhs) {
    Seg res;
    res.min = min(lhs.min, rhs.min);
    if (lhs.min == rhs.min) {
        res.cnt = lhs.cnt + rhs.cnt;
    }
    else {
        res.cnt = (lhs.min < rhs.min ? lhs.cnt : rhs.cnt);
    }
    res.odd = lhs.odd + rhs.odd;
    res.even = lhs.even + rhs.even;
    return res;
}

struct SegTree {
    int n;
    vector<Seg> tree;
    vector<int> lazy;
    SegTree(int _n): n(1) {
        while (n < _n) n *= 2;
        tree.resize(n * 2);
        lazy.resize(n * 2);
    }
    void pull(int x) {
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
    }
    void push(int x) {
        if (!lazy[x]) return;

        tree[x * 2].add(lazy[x]);
        tree[x * 2 + 1].add(lazy[x]);

        lazy[x * 2] += lazy[x];
        lazy[x * 2 + 1] += lazy[x];

        lazy[x] = 0;
    }
    void build(int x, int l, int r) {
        if (l == r) {
            int range = vals[l + 1] - vals[l];
            tree[x] = Seg(0, range, 0, range);
            return;
        }
        int mid = (l + r) >> 1;
        build(x * 2, l, mid);
        build(x * 2 + 1, mid + 1, r);
        pull(x);
    }
    void add(int x, int l, int r, int u, int v, int amt) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            tree[x].add(amt);
            lazy[x] += amt;
            return;
        }
        int mid = (l + r) >> 1;
        push(x);
        add(x * 2, l, mid, u, v, amt);
        add(x * 2 + 1, mid + 1, r, u, v, amt);
        pull(x);
    }
    Seg query_all() {
        return tree[1];
    }
};  

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<array<int, 4>> events;
    for (int i = 0; i < n; ++i) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        if (x == xx || y == yy) continue;
        if (x > xx) swap(x, xx);
        if (y > yy) swap(y, yy);

        events.push_back({x, 1, y, yy}); events.push_back({xx, -1, y, yy});
        vals.push_back(y); vals.push_back(yy);
    }
    if (events.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    sort(events.begin(), events.end(), [](const auto &lhs, const auto &rhs) {
        if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
        return lhs[0] < rhs[0];
    });
    sort(vals.begin(), vals.end());

    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = (int) vals.size() - 1;
    SegTree tree(m);
    tree.build(1, 0, m - 1);

    int last = -INF;
    long long res = 0;
    for (const auto &[x, delta, y, yy] : events) {
        Seg seg = tree.query_all();
        res += 1LL * (x - last) * (seg.even - (seg.min == 0 ? seg.cnt : 0));
        int cy = lower_bound(vals.begin(), vals.end(), y) - vals.begin();
        int cyy = lower_bound(vals.begin(), vals.end(), yy) - vals.begin() - 1;
        tree.add(1, 0, m - 1, cy, cyy, delta);
        last = x;
    }
    cout << res << '\n';

    return 0;
}
