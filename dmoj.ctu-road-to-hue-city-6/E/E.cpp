/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

const int N = 50;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, K;
    cin >> n >> m >> K;
    vector<int> dp(K + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> next_dp(K + 1);
        for (int k = 1; k <= K; ++k) {
            for (int j = 1; j <= min(m, k); ++j) {
                next_dp[k] += dp[k - j];
                if (next_dp[k] >= MOD) {
                    next_dp[k] -= MOD;
                }
            }
        }
        dp.swap(next_dp);
    }
    int res = 0;
    for (int i = n; i <= K; ++i) {
        res += dp[i];
        if (res >= MOD) res -= MOD;
    }
    cout << res << '\n';

	return 0;
}
