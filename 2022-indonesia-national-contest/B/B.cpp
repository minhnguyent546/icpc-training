#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> t(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> t[i];
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        pref[i + 1] = pref[i] + t[i];
    }
    auto get = [&](int l, int r) -> int {
        assert(l <= r);
        return pref[r + 1] - pref[l];
    };
    long long cost = 0;
    for (int i = n - 1, ptr = n - 1; i >= 0; --i) {
        int need = max(0, b[i] - a[i]);
        if (need == 0) {
            continue;
        }
        ptr = min(ptr, i - 1);
        while (ptr >= 0 && need > 0) {
            int add = min(need, a[ptr]);
            need -= add;    
            a[ptr] -= add;
            cost += 1LL * get(ptr, i - 1) * add;
            if (a[ptr] == 0) --ptr;
        }
        if (need > 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << cost << '\n';

    return 0;
}
