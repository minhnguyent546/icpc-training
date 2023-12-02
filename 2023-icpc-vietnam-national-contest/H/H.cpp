#include <bits/stdc++.h>
using namespace std;

#define hi cerr << "HiHiHi\n";

#ifndef LOCAL
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e7 + 7;

struct SegTree {
    int n;
    vector<long long> tree;
    SegTree() {}
    SegTree(int _n): n(_n) {
        tree.resize(n * 2);
    }
    void pull(int x) {
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
    }
    void assign(int i, long long val) {
        tree[i += n] = val;
        for (i /= 2; i > 0; i /= 2) {
            pull(i);
        }
    }
    long long query(int l, int r) {
        assert(l <= r);
        long long res = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

inline long long sqr(int x) {
    return 1LL * x * x;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        --arr[i];
    }
    vector<vector<int>> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[arr[i]].push_back(i);
    }
    vector<SegTree> tree(n);
    for (int i = 0; i < n; ++i) {
        if (indices[i].empty()) continue;
        int sz = (int) indices[i].size();
        tree[i] = SegTree(sz);
        for (int j = 0; j < sz; ++j) {
            tree[i].assign(j, sqr(indices[i][j] + 1));
        }
    }
    // for (int i = 0; i < n; ++i) {
    //  if (indices[i].empty()) continue;
    //  cerr << "val: " << i << '\n';
    //  for (int j : indices[i]) {
    //      cerr << j << ' ';
    //  }
    //  cerr << '\n';
    //  cerr << "query all: " << tree[i].tree[1] << '\n';
    // }
    // cerr << "try: " << tree[0].query(0, 2) << '\n';
    long long last = 0;
    for (int w = 0 ; w < q; ++w) {
        int type;
        cin >> type;
        int pos, l, r, x;
        if (type == 1) {
            cin >> pos;
            pos = ((pos + last - 1) % (n - 1)) + 1;
            --pos;
        }
        else {
            cin >> l >> r >> x;
            l = ((l + last - 1) % n) + 1;
            r = ((r + last - 1) % n) + 1;
            x = ((x + last - 1) % n) + 1;
            --l; --r; --x;
            if (l > r) swap(l, r);
        }
        if (type == 1) {
            assert(pos + 1 < n);
            if (arr[pos] == arr[pos + 1]) {
                continue;
            }
            auto it_left = lower_bound(indices[arr[pos]].begin(), indices[arr[pos]].end(), pos) - indices[arr[pos]].begin();
            assert(indices[arr[pos]][it_left] == pos);
            tree[arr[pos]].assign(it_left, sqr(pos + 1 + 1));
            indices[arr[pos]][it_left] = pos + 1;

            auto it_right = lower_bound(indices[arr[pos + 1]].begin(), indices[arr[pos + 1]].end(), pos) - indices[arr[pos + 1]].begin();
            assert(indices[arr[pos + 1]][it_right] == pos + 1);
            tree[arr[pos + 1]].assign(it_right, sqr(pos + 1));
            indices[arr[pos + 1]][it_right] = pos;

            swap(arr[pos], arr[pos + 1]);
        }
        else if (type == 2) {
            auto &v = indices[x];
            auto it_l = lower_bound(v.begin(), v.end(), l) - v.begin();
            auto it_r = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
            if (it_l > it_r) {
                last = 0;
            }
            else {
                last = tree[x].query(it_l, it_r);
            }
            // cout << last << '\n';
            // cerr << "DEBUG val at 117" << '\n';
            // for (int val : v) {
            //  cerr << val << ' ';
            // }
            // cerr << '\n';
            // cerr << tree[x].query(it_l, it_r) << '\n';
            // cerr << "res: " << last << '\n';
            cout << last << '\n';
            // cerr << "w: " << w << ' ' << "type: " << type << ' '  << "l, r, x: " << l << ", " << r << ", " << x << ' ' << "it_l: " << it_l << ' '  << "it_r: " << it_r << ' ' << "last: " << last << '\n';
        }
        else if (type == 3) {
            auto &v = indices[x];
            assert(r < (int) v.size());
            // if (r >= (int) v.size()) {
            //  cerr << "failed at: " << w << ' '  << x << ' ' << r << ' ' << v.size() << '\n'
            // }
            last = tree[x].query(l, r);
            // cout << last << '\n';
            // cerr << "res: " << last << '\n';
            cout << last << '\n';
            // cerr << last << '\n';
            // cerr << "w: " << w << ' ' << "type: " << type << ' '  << "l, r, x: " << l << ", " << r << ", " << x << ' ' << "last: " << last << '\n';
        }
        else assert(false);
    }
    return 0;
}
