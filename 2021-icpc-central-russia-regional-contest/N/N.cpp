#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }
    map<int,vector<int>> listId;
    for(int i = 0; i < n; i++) {
        listId[a[i]].push_back(i);
    }
    int q;
    cin >> q;
    int d = 0;
    while(q--) {
        char type;
        int val;
        cin >> type >> val;
        if(type == 's') {
            d = (d + val + n) % n;
        } else {
            if(listId.find(val) == listId.end()) {
                cout << -1 << '\n';
            } else {
                int res = (listId[val][0] + d) % n;
                int it = lower_bound(listId[val].begin(), listId[val].end(), n - d) - listId[val].begin();
                if(it >= 0 && it < listId[val].size()) {
                    res = min(res, (listId[val][it] + d) % n);
                }
                cout << res + 1 << '\n';
            }
        }
    }
    return 0;
}
