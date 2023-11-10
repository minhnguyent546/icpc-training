#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        for(int &x : w) {
            cin >> x;
        }
        int d;
        cin >> d;
        vector<string> s(d);
        vector<vector<int>> cnt(27, vector<int>(51));
        for(int i = 0; i < d; i++) {
            cin >> s[i];
            int c = s[i][0] - 'a';
            cnt[c][s[i].length()]++;
        }
        int ans = 0;
        for(int i = 0; i < d; i++) {
            if(s[i].length() != n) {
                continue;
            }
            int c = s[i][0] - 'a';
            cnt[c][s[i].length()]--;
            int res = 1;
            vector<pair<int,int>> roll;
            for(int j = 0; j < s[i].length(); j++) {
                int c = s[i][j] - 'a';
                int len = w[j];
                if(cnt[c][len] == 0) {
                    res = 0;
                    break;
                } else {
                    res *= cnt[c][len];
                    res %= MOD;
                    cnt[c][len]--;
                    roll.push_back({c, len});
                }
            }
            cnt[c][s[i].length()]++;
            ans += res;
            ans %= MOD;
            for(auto[c, len] :  roll) {
                cnt[c][len]++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
