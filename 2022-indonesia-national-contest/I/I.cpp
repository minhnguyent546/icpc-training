#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

const int N = (int) 2e5;
const int SZ = 750;
int T[SZ][N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    string bar;
    cin >> bar;
    for (int i = 0; i < n; ++i) {
        arr[i] = (bar[i] == '0' ? 1 : 0);
    }
    int s = (int) sqrt(n);
    for (int k = 1; k <= s; ++k) {
        for (int i = 0; i < n; ++i) {
            T[k][i % k] += arr[i];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        int x;
        int K;
        cin >> type >> x;
        --x;
        if (type == 3) cin >> K;
        if (type == 1) {
            assert(arr[x] == 1);
            arr[x] = 0;
            for (int k = 1; k <= s; ++k) {
                T[k][x % k]--;
            }
        }
        else if (type == 2) {
            assert(arr[x] == 0);
            arr[x] = 1;
            for (int k = 1; k <= s; ++k) {
                T[k][x % k]++;
            }
        }
        else if (type == 3) {
            int res;
            if (K > s) {
                res = 0;
                for (int i = x; i < n; i += K) {
                    res += arr[i];
                }
            }
            else {
                res = T[K][x];
            }
            cout << res << '\n';
        }
        else assert(false);
    }
    return 0;
}
