/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n);
    for (int i = 0; i < n; ++i) {
        int buy;
        cin >> buy;
        cost[i] = {buy};
        for (int j = 0; j < min(m, n - i); ++j) {
            int sell;
            cin >> sell;
            cost[i].push_back(sell);
        }
    }
    vector<long long> dp(n + 1, (long long) 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= max(1, i - m + 1); --j) {
            assert(i - j + 1 < (int) cost[j - 1].size());
            dp[i] = min(dp[i], dp[j - 1] + cost[j - 1][0] - cost[j - 1][i - j + 1]);
        }
    }
    cout << dp[n] << '\n';

	return 0;
}
