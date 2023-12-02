#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    vector<int> a(n + 2);
    a[0] = 1;
    a[n + 1] = 1;
    auto f = [&](long long n) -> long long {
        return (n + 1) * (n + 1) * n / 2 - n * (n + 1) * (2 * n + 1) / 6;
    };
    long long sum = f(n);
    while(q--) {
        int x;
        cin >> x;
        a[x] = 1 - a[x];
        if(!a[x]) s.erase(x);
        auto it = s.upper_bound(x);
        int l = *prev(it), r = *it;
        if(a[x]) {
            sum += - f(r - l - 1) + f(x - l - 1) + f(r - x - 1);
        } else {
            sum -= - f(r - l - 1) + f(x - l - 1) + f(r - x - 1);
        }
        cout << sum << endl;
        if(a[x]) s.insert(x);
    }
    return 0;
}
