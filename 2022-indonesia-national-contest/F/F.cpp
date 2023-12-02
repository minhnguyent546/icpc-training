#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, p0, x;
    cin >> n >> p0 >> x;
    vector<ll> p(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    ll ans = (ll)1e18;
    for(int i = 0; i <= n; i++) {
        ll k = (x - p[i] - p0) / p[n];
        if(k >= 0 && p0 + p[i] + k * p[n] >= x) ans = min(ans, p0 + p[i] + k * p[n]);
    }
    cout << (ans == (ll)1e18 ? -1 : ans) << endl; 
    return 0;
}
