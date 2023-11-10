#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

#define int long long

int n, k;
vector<int> h;

int calc(vector<int> &arr) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int l = -1, r = -1;
        for (int j = i - 1; j >= 0; --j) {
            l = max(l, arr[j]);
        }
        for (int j = i + 1; j < n; ++j) {
            r = max(r, arr[j]);
        }
        if (l <= arr[i] || r <= arr[i]) continue;
        res += min(l, r) - arr[i];
    }
    return res;
}

int dq(int k, int i, int j, vector<int> &state) {
    int res = 0;
    for(int coin = 0; coin <= k; coin++) {
        state[i] += coin;
        state[j] += k - coin;
        res = max(res, calc(state));
        state[i] -= coin;
        state[j] -= k - coin;
    }
    return res;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    h.resize(n);
    for(int &x : h) {
        cin >> x;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int t = j + 1; t < n; t++) {
                for(int coin = 0; coin <= k; coin++) {
                    h[i] += coin;
                    ans = max(ans, dq(k - coin, j, t, h));
                    h[i] -= coin;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
