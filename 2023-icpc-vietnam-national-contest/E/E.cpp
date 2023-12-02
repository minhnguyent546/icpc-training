#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#endif

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e7 + 7;

bool check(int a, int b, int n) {
    if(a - b >= 2 && a >= n)
        return false;
    if(b - a >= 2 && b >= n)
        return false;
    return true;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(abs(a - b) < 2 || max(a, b) < n) {
            cout << 0 << '\n';
            continue;
        }
        vector<vector<int>> dp(11, vector<int>(11, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= 10; i++) {
            for(int j = 0; j <= 10; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(j - 1 >= 0 && dp[i][j - 1] != 0 && check(i, j - 1, n)) {
                    dp[i][j] += dp[i][j - 1];
                }
                if(i - 1 >= 0 && dp[i - 1][j] != 0 && check(i - 1, j, n)) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
        cout << dp[a][b] << '\n';
    }
    return 0;
}
