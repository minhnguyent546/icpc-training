#include <bits/stdc++.h>

using namespace std;

#define int long long 

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        s = "#" + s;
        int n = (int)s.size() - 1;
        vector<int> dp(n + 1);
        vector<int> count(26), contains(26);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + i - count[s[i] - 'a'] - contains[s[i] - 'a'];
            contains[s[i] - 'a'] = i  - count[s[i] - 'a'];
            count[s[i] - 'a'] = i;
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
            res += dp[i];
        cout << res << '\n';
    }

    return 0;
}
