#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int cnt = 0;
    int best = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int minv = min({arr[i], arr[j], arr[k]});
                int maxv = max({arr[i], arr[j], arr[k]});
                if (maxv - minv <= m) {
                    ++cnt;
                    best = max(best, arr[i] + arr[j] + arr[k]);
                }
            }
        }
    }
    if (!cnt) {
        cout << -1 << '\n';
        return 0;
    }
    cout << cnt << ' '  << best << '\n';
    return 0;
}