/**            
 * author      minhnguyent546
 * created_at  Sat, 2023-10-07 15:54:20
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

struct FT {
    int n;
    vector<int> tree;
    FT(int _n): n(_n) {
        tree.resize(n);
    }
    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }
    void add(int pos, int val) {
        for (int i = pos; i < n; i |= (i + 1)) tree[i] += val;
    }
    int query(int pos) {
        int res{};
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) res += tree[i];
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        --arr[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&arr](int i, int j) {
        return arr[i] < arr[j];
    });
    vector<long long> left(n), right(n);
    FT tree(n);
    for (int i = 1; i < n; ++i) {
        int cur = tree.query(order[i - 1] + 1, n - 1);
        left[arr[order[i]]] = cur + left[arr[order[i - 1]]];
        tree.add(order[i - 1], 1);
    }
    tree.clear();
    for (int i = n - 2; i >= 0; --i) {
        int cur = tree.query(order[i + 1] - 1);
        right[arr[order[i]]] = cur + right[arr[order[i + 1]]];
        tree.add(order[i + 1], 1);
    }
    long long res = (long long) 1e18;
    for (int i = 0; i < n; ++i) {
        res = min(res, left[i] + right[i]);
    }
    cout << res << '\n';
    return 0;
}
