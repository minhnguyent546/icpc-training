#include <bits/stdc++.h>

using namespace std;

struct FT {
    int n;
    vector<int> tree;
    FT() {}
    FT(int _n): n(_n) {
        tree.resize(n);
    }
    void add(int pos, int val) {
        for (int i = pos; i < n; i |= (i + 1)) {
            tree[i] += val;
        }
    }
    void add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
    int query(int pos) {
        int res{};
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
            res += tree[i];
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = (int) s.size();
    int k;
    cin >> k;
    FT tree(n);
    for (int w = 0; w < k; ++w) {
        int amt, l, r;
        cin >> amt >> l >> r;
        --l; --r;
        tree.add(l, r, amt);
    }
    const char minchar = 'A';
    const int ALPHABET = 26;
    for (int i = 0; i < n; ++i) {
        int cur = s[i] - minchar;
        int next = (cur + tree.query(i)) % ALPHABET;
        s[i] = (char) (next + minchar);
    }
    cout << s << '\n';
    return 0;
}
