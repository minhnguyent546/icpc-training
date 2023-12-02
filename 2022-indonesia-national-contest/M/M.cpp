#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = 0;
    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (abs(a[i] - a[i - 2]) == 2 || abs(a[i] - a[i -2]) == 0) {
            r = i;
        } else {
            ans = max(ans, (r - l) + 1 + (l - 1 >= 0 ? a[l - 1] == 0 : 0) + (r + 1 < n ? a[r + 1] == 0 : 0));
            l = i;
        }
    }

    ans = max(ans, (r - l) + 1 + (l - 1 >= 0 ? a[l - 1] == 0 : 0) + (r + 1 < n ? a[r + 1] == 0 : 0));

    cout << ans;

    return 0;
}