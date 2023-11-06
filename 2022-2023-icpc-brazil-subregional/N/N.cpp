#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct FT {
    int n;
    vector<int> bit;

    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void add(int x, int val) {
        for(int i = x + 1; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    int get(int x) {
        int res = 0;
        for(int i = x + 1; i >= 1; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }

    int get(int l, int r) {
        if(l == 0)
            return get(r);
        return get(r) - get(l - 1);
    }
};

vector<int> calPrefix(vector<int> &a) {
    vector<int> res(a.begin(), a.end());
    for(int i = 1; i < res.size(); i++) {
        res[i] += res[i - 1];
    }
    return res;
}

int getPrefix(vector<int> &a, int l, int r) {
    if(l == 0)
        return a[r];
    return a[r] - a[l - 1];
}

int bsId(FT &fen, int val) {
    int l = 0, r = fen.n - 1, res = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(fen.get(m, fen.n - 1) < val) {
            r = m - 1;
        } else {
            res = m;
            l = m + 1;
        }
    }
    return res;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    int k, l;
    cin >> k >> l;
    vector<int> preA = calPrefix(a);
    vector<int> vals;
    for(int i = 0; i < n; i++) {
        vals.push_back(b[i]);
    }
    sort(vals.begin(), vals.end());
    FT fen1, fen2;
    fen1.init(n);
    fen2.init(n);
    int sumA = 0;
    for(int i = 0; i < k; i++) {
        int val = b[i];
        int idVal = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
        fen1.add(idVal, val);
        fen2.add(idVal, 1);
        sumA += a[i];
    }
    int ans = fen1.get(bsId(fen2, l), n - 1) + sumA;
    for(int i = 1; i <= k; i++) {
        int val = b[k - i];
        sumA -= a[k - i];
        int idVal = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
        fen1.add(idVal, -val);
        fen2.add(idVal, -1);
        val = b[n - i];
        sumA += a[n - i];
        idVal = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
        fen1.add(idVal, val);
        fen2.add(idVal, 1);
        ans = max(ans, fen1.get(bsId(fen2, l), n - 1) + sumA);
    }
    cout << ans;
    return 0;
}
