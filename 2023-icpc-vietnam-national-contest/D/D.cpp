#include <bits/stdc++.h>
using namespace std;

#define hi cerr << "HiHiHi\n";

#ifndef LOCAL
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e7 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            --arr[i];
        }
        long long res = 0;
        vector<bool> vis(n);
        for (int l = 0, r = -1; l < n; ++l) {
            while (r + 1 < n && !vis[arr[r + 1]]) {
                ++r;
                vis[arr[r]] = true;
            }
            res += r - l + 1;
            vis[arr[l]] = false;
        }
        cout << res << '\n';
    }

    return 0;
}
