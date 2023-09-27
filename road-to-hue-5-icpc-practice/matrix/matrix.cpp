/**            
 * author      minhnguyent546
 * created_at  Wed, 2023-09-27 10:06:24
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (119 << 23) + 1;
const int INF = 0x3f3f3f3f;

const int N = 400;
const int NN = N * N;
int mat[N][N], dp[N + 1][N + 1];
int freq[NN + 1], fact[NN + 1], inv_fact[NN + 1];
vector<pair<int, int>> indices[N * N + 1];
int n;

int powmod(long long a, long long n, int mod = MOD) {
    a %= mod;
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void precompute(int n = NN) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    inv_fact[n] = powmod(fact[n], MOD - 2);
    for (int i = n; i > 0; --i) {
        inv_fact[i - 1] = 1LL * inv_fact[i] * i % MOD;
    }
}

int comb(int val) {
    int res = 0;
    auto &v = indices[val];
    for (int i = 0; i < (int) v.size(); ++i) {
        for (int j = i; j < (int) v.size(); ++j) {
            int dr = v[i].first - v[j].first;
            int dc = v[i].second - v[j].second;
            if (dr <= 0) {
                dr *= -1;
                dc *= -1;
            }
            if ((dr ^ dc) < 0) continue;
            int cur = (1LL * fact[dr + dc] * inv_fact[dr] % MOD) * inv_fact[dc] % MOD;
            res += cur;
            if (res >= MOD) res -= MOD;
        }
    }
    return res;
}

int dyn(int val) {
    auto &v = indices[val];
    memset(dp, 0, sizeof dp);
    for (auto [i, j] : v) {
        dp[i + 1][j + 1] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (1LL * dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    int res = 0;
    for (auto [i, j] : v) {
        res = (res + dp[i + 1][j + 1]);
        if (res >= MOD) res -= MOD;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    precompute();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
            ++freq[mat[i][j]];
            indices[mat[i][j]].emplace_back(i, j);
        }
    }
    int res = 0;
    for (int val = 1; val <= n * n; ++val) {
        int ans = (freq[val] <= n ? comb(val) : dyn(val));
        res += ans;
        if (res >= MOD) res -= MOD;
    }
    cout << res << '\n';
    
    // time complexity: O(N^3)
    return 0;
}
