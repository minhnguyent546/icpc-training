#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

inline void ensure(int &x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, K, p;
    cin >> n >> K >> p;
    vector<vector<int>> dp(n + 1, vector<int>(p + 1));
    for (int i = 0; i <= p; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            int r = j - 1;
            int l = j - min(j, K);
            assert(l <= r);
            dp[i][j] = dp[i - 1][r] - (l > 0 ? dp[i - 1][l - 1] : 0);
            ensure(dp[i][j]);
        }
        for (int j = 1; j <= p; ++j) {
            dp[i][j] += dp[i][j - 1];
            ensure(dp[i][j]);
        }
    }
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res = 1LL * res * K % MOD;
    }
    res -= dp[n][p];
    ensure(res);
    cout << res << '\n';
    return 0;
}
