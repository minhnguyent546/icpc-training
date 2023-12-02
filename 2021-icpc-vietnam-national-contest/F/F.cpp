#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    long long res = accumulate(dp[n].begin(), dp[n].end(), 0LL);
    cout << res << '\n';

    return 0;
}
