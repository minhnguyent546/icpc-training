#include <bits/stdc++.h>
using namespace std;


#ifndef LOCAL
#endif

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int N = (int) 20;
int f[N + 3];

int n;
int ans;

inline void ensure(int &x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
}
int step = 0;

void dp(int i, vector<int> par, int res) {
    if (i == n) {
        ans += res;
        ensure(ans);
        return;
    }
    ++step;
    vector<int> new_par;
    for (int k = 1; k <= (int) par.size(); ++k) {
        new_par.push_back(par[k - 1]);
        new_par.push_back(i);
        dp(i + 1, new_par, 1LL * res * f[k - 1] % MOD);
        new_par.pop_back();
    }
}

void precompute() {
    f[0] = 1;
    for (int i = 1; i <= N; ++i) {
        f[i] = 2LL * f[i - 1] % MOD;
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    precompute();
    cin >> n;
    vector<int> vers(n);
    if(n == 1) {
        cout << 1;
        return 0;
    }
    dp(1, {0}, 1);
    cout << ans << '\n';
    return 0;
}
