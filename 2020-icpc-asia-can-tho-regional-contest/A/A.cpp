#include<bits/stdc++.h>
using namespace std;


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int rem = n % 4;
        if (rem == 0) {
            cout << n << '\n';
            for (int i = 1; i <= n; ++i) {
                cout << i << ' ';
            }
        }
        else if (rem == 1) {
            if (n == 1) {
                cout << 1 << '\n';
                cout << 1;
            }
            else {
                cout << n - 1 << '\n';
                for (int i = 1; i <= n; ++i) {
                    if (i == n - 1) continue;
                    cout << i << ' ';
                }
            }
        }
        else if (rem == 2) {
            cout << n - 1 << '\n';
            for (int i = 2; i <= n; ++i) {
                cout << i << ' ';
            }
        }
        else if (rem == 3) {
            cout << n - 1 << '\n';
            for (int i = 1; i <= n - 1; ++i) {
                cout << i << ' ';
            }
        }
        else assert(false);
        cout << '\n';   
    }
}
