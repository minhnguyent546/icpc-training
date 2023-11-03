#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int zero = 0, neg = 0;
    const int MOD = (int) 1e9 + 7;
    const int INF = 0x3f3f3f3f;
    for (int v : arr) {
        if (v == 0) ++zero;
        else if (v < 0) ++neg;
    }
    long long res = 1;
    if (zero >= 2) {
        res = 0;
    }
    else if (zero == 1) {
        if (neg & 1) res = 0;
        else {
            for (int v : arr) {
                if (v == 0) continue;
                res = 1LL * res * v % MOD;
            }
        }
    }
    else {
        if (neg & 1) {
            int largest_neg = -INF;
            for (int v : arr) {
                if (v >= 0) continue;
                largest_neg = max(largest_neg, v);
            }
            for (int v : arr) {
                if (v == largest_neg) continue;
                res = 1LL * res * v % MOD;
            }
        }
        else {
            for (int v : arr) res = 1LL * res * v % MOD;
        }
    }
    cout << res << '\n';

    return 0;
}
