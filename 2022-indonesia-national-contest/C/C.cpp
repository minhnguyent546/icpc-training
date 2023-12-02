#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;
const int MOD[] = {(int) 1e9 + 9, (int) 1e9 + 9};

const int N = (int) 2e5 + 13;
int pw[2][N + 1];

inline void ensure(int i, int &x) {
    if (x >= MOD[i]) x -= MOD[i];
    else if (x < 0) x += MOD[i];
}

void precompute(int n = N) {
    pw[0][0] = pw[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[0][i] = 2 * pw[0][i - 1] % MOD[0];
        pw[1][i] = 2 * pw[1][i - 1] % MOD[1];
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    precompute();
    int q;
    cin >> q;
    int pos[] = {0, 0}, neg[] = {0, 0};
    for (int w = 0; w < q; ++w) {
        char ch;
        int x;
        cin >> ch >> x;
        if (ch == '+') {
            pos[0] += pw[0][x];
            pos[1] += pw[1][x];
        }   
        else if (ch == '-') {
            neg[0] += pw[0][x];
            neg[1] += pw[1][x];
        }
        else assert(false);
        ensure(0, pos[0]);
        ensure(1, pos[1]);
        ensure(0, neg[0]);
        ensure(1, neg[1]);
        cout << (pos[0] == neg[0] && pos[1] == neg[1] ? "YES" : "NO") << '\n';
    }

    return 0;
}
