/**            
 * author      minhnguyent546
 * created_at  Tue, 2023-09-26 18:16:30
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    long long k;
    cin >> n >> k;
    long long kk = k * k;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&points](int i, int j) {
        return points[i] < points[j];
    });
    vector<pair<int, int>> ans;
    set<pair<int, int>> st;
    for (int i = 0, ptr = 0; i < n; ++i) {
        while (points[order[ptr]].first < points[order[i]].first - k) {
            st.erase({points[order[ptr]].second, order[ptr]});
            ++ptr;
        }
        auto [x, y] = points[order[i]];
        auto it = st.lower_bound({y - k, -INF});
        while (it != st.end() && it->first <= y + k) {
            int idx = it->second;
            int dx = x - points[idx].first;
            int dy = y - points[idx].second;
            long long dist = 1LL * dx * dx + 1LL * dy * dy;
            if (dist <= kk) {
                ans.emplace_back(minmax(idx, order[i]));
            }
            it++;
        }
        st.emplace(y, order[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto [p, q] : ans) {
        cout << p + 1 << ' ' << q + 1 << '\n';
    }
    return 0;
}
