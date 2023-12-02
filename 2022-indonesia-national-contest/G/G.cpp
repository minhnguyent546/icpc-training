#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
// const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    vector<pair<pair<char, int>, pair<char, int>>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
    }
    vector<array<long long, 2>> dp(n + 1, {INF_LL, -INF_LL});
    dp[0] = {p, p};
    auto cal = [&](long long a, char op, int x) -> long long {
        if (op == '+') return a + x;
        else if (op == 'x') return a * x;
        else assert(false);
        return -1;
    };
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min({cal(dp[i - 1][0], arr[i - 1].first.first, arr[i - 1].first.second),
                        cal(dp[i - 1][0], arr[i - 1].second.first, arr[i - 1].second.second),
                        cal(dp[i - 1][1], arr[i - 1].first.first, arr[i - 1].first.second),
                        cal(dp[i - 1][1], arr[i - 1].second.first, arr[i - 1].second.second)
        });
        dp[i][1] = max({cal(dp[i - 1][0], arr[i - 1].first.first, arr[i - 1].first.second),
                        cal(dp[i - 1][0], arr[i - 1].second.first, arr[i - 1].second.second),
                        cal(dp[i - 1][1], arr[i - 1].first.first, arr[i - 1].first.second),
                        cal(dp[i - 1][1], arr[i - 1].second.first, arr[i - 1].second.second)
        });
    }
    cout << dp[n][1] << '\n';
    return 0;
}