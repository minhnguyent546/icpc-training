#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int BASE = 31;
const int K = 4;
vector<int> arr[K];
int m[K];
vector<int> h(K);
int pw[33];

map<vector<int>, int> f;
int solve() {
    bool any = false;
    for (int i = 0; i < K; ++i) {
        if (!arr[i].empty()) {
            any = true;
        }
    }
    if (!any) {
        return 0;
    }
    if (f.count(h)) {
        return f[h];
    }
    int res = INF;
    vector<int> will(K, INF);
    for (int i = 0; i < K; ++i) {
        if (!arr[i].empty()) will[i] = arr[i].back();
    }
    for (int c : will) {
        if (c == INF) continue;
        vector<vector<int>> rm(K);
        for (int i = 0; i < K; ++i) {
            while (!arr[i].empty() && arr[i].back() == c) {
                int idx = (int) arr[i].size() - 1;
                rm[i].push_back(arr[i].back());
                h[i] -= (1LL * arr[i].back() * pw[m[i] - idx - 1]);
                arr[i].pop_back();
            }
        }
        res = min(res, solve());
        for (int i = 0; i < K; ++i) {
            while (!rm[i].empty()) {
                arr[i].push_back(rm[i].back());
                int idx = (int) arr[i].size() - 1;
                h[i] += (1LL * arr[i].back() * pw[m[i] - idx - 1]);
                rm[i].pop_back();
            }
        }
    }
    return f[h] = res + 1;
};

void precompute() {
    pw[0] = 1;
    for (int i = 1; i <= 30; ++i) {
        pw[i] = 1LL * pw[i - 1] * BASE % MOD;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    precompute();
    int n;
    cin >> n;
    for (int i = 0; i < K; ++i) {
        cin >> m[i];
        arr[i].resize(m[i]);
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < m[i]; ++j) {
            cin >> arr[i][j];
        }
        h[i] = 0;
        for (int j = 0; j < m[i]; ++j) {
            h[i] = (h[i] + 1LL * arr[i][j] * pw[m[i] - j - 1]) % MOD;
        }
    }

    int res = solve();
    cout << res << '\n';
    return 0;
}
